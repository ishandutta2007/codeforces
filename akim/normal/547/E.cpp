#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 200100;

string s[maxn];
int bor[maxn][26], sz = 1, prefs[maxn], pr[maxn], pos[maxn], ch[maxn];
int zp[maxn][26];
vector<int> rb[maxn];
int val[maxn];
int bg[maxn], en[maxn], nm = 0;
int lpos;
int ans[5 * maxn];
vector<pair<pair<int, int>, pair<int, int> > > vc;

void add(string &s) {
	int pos = 0;
	for(int i = 0; i < (int)s.length(); i++) {
		if(bor[pos][s[i] - 'a'] == 0) {
			pr[sz] = pos;
			ch[sz] = s[i] - 'a';
			bor[pos][s[i] - 'a'] = sz++;
		}
		pos = bor[pos][s[i] - 'a'];
	}
	lpos = pos;
}

void topsort(int u = 0) {
	bg[u] = nm++;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		topsort(rb[u][i]);
	}
	en[u] = nm;
}

void addfv(int u) {
	for(; u < maxn; u |= u + 1) {
		val[u]++;
	}
}
int getfv(int u) {
	int ret = 0;
	for(; u >= 0; u &= u + 1, u--) {
		ret += val[u];
	}
	return(ret);
}

void addtp(string &s) {
	int pos = 0;
	for(int i = 0; i < (int)s.length(); i++) {
		pos = bor[pos][s[i] - 'a'];
		addfv(bg[pos]);
	}
}

int go(int u, int c);

int getlink(int u) {
	if(prefs[u] == 0) {
		if(u == 0 || pr[u] == 0) {
			prefs[u] = 0;
		} else {
			prefs[u] = go(getlink(pr[u]), ch[u]);
		}
	}
	return(prefs[u]);
}

int go(int u, int c) {
	if(zp[u][c] == 0) {
		if(bor[u][c] != 0) {
			zp[u][c] = bor[u][c];
		} else {
			zp[u][c] = u == 0 ? 0 : go(getlink(u), c);
		}
	}
	return(zp[u][c]);
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int n, m;
	scanf("%d%d\n", &n, &m);
	for(int i = 0; i < n; i++) {
		getline(cin, s[i]);
		add(s[i]);
		pos[i] = lpos;
	}

	getlink(0);
	for(int i = 1; i < sz; i++) {
		rb[getlink(i)].pb(i);
	}

	topsort();

	for(int i = 0; i < m; i++) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		l--, r--, k--;
		vc.pb(mp(mp(l - 1, i), mp(k, -1)));
		vc.pb(mp(mp(r, i), mp(k, 1)));
	}

	sort(vc.begin(), vc.end());

	int f = 0;
	for(int i = 0; i < (int)vc.size(); i++) {
		while(f <= vc[i].fs.fs) {
			addtp(s[f++]);
		}
		ans[vc[i].fs.sc] += vc[i].sc.sc * (getfv(en[pos[vc[i].sc.fs]] - 1) - getfv(bg[pos[vc[i].sc.fs]] - 1));
	}

	for(int i = 0; i < m; i++) {
		printf("%d\n", ans[i]);
	}

	return(0);
}

// by Kim Andrey