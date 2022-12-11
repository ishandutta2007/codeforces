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
const int maxn = 3 * 100100;

vector<pair<int, pair<int, int> > > rb[maxn];
vector<int> vc;
priority_queue<pair<ll, pair<int, pair<int, int> > > > q;
bool pm[maxn];

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
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		rb[u].pb(mp(v, mp(c, i + 1)));
		rb[v].pb(mp(u, mp(c, i + 1)));
	}
	int a;
	scanf("%d", &a);
	q.push(mp(0, mp(0, mp(0, a))));
	ll ans = 0;
	while(!q.empty()) {
		ll u = q.top().sc.sc.sc;
		if(pm[u]) {
			q.pop();
			continue;
		}
		pm[u] = 1;
		ll d = q.top().fs, lr = q.top().sc.fs, r = q.top().sc.sc.fs;
		q.pop();
		vc.pb(r);
		ans += (-lr);
		for(int i = 0; i < (int)rb[u].size(); i++) {
			if(!pm[rb[u][i].fs]) {
				ll v = rb[u][i].fs, c = rb[u][i].sc.fs, nm = rb[u][i].sc.sc;
				q.push(mp(d - c, mp(-c, mp(nm, v))));
			}
		}
	}

	printf("%I64d\n", ans);
	for(int i = 1; i < (int)vc.size(); i++) {
		printf("%d ", vc[i]);
	}

	return(0);
}

// by Kim Andrey