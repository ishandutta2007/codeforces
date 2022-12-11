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
const int maxn = 2 * 100100;

ll hash[26], shash[maxn][26], md = 27, pr[26];
vector<int> ans;
vector<pair<ll, ll> > cmp, cmp1, cmp2;

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
	string s, t;
	getline(cin, s);
	getline(cin, t);
	for(int f = 0; f < 26; f++) {
		ll mmd = 1;
		for(int i = 0; i < m; i++) {
			hash[f] += (f == (t[i] - 'a')) ? mmd : 0;
			hash[f] %= mod;
			mmd *= md;
			mmd %= mod;
		}
		if(hash[f]) {cmp.pb(mp(hash[f], f));}
	}
	ll mmd = 1, mmd2 = 1;
	for(int i = 0; i < n; i++) {
		int same = 0;
		cmp1.clear();
		cmp2.clear();

		for(int f = 0; f < 26; f++) {
			pr[f] = f;
		}

		for(int f = 0; f < 26; f++) {
			shash[i][f] = (i - 1 >= 0 ? shash[i - 1][f] : 0) + ((f == s[i] - 'a') ? mmd : 0) % mod;
			if((shash[i][f] - (i - m >= 0 ? shash[i - m][f] : 0) + mod) % mod) cmp2.pb(mp((shash[i][f] - (i - m >= 0 ? shash[i - m][f] : 0) + mod) % mod, f));
		}

		if(i - m == -1) {mmd2 = 1;}
		for(int f = 0; f < (int)cmp.size(); f++) {
			cmp1.pb(mp(cmp[f].fs * mmd2 % mod, cmp[f].sc));
		}

		sort(cmp1.begin(), cmp1.end());
		sort(cmp2.begin(), cmp2.end());
		if(cmp1.size() == cmp2.size())
			for(int f = 0; f < (int)cmp1.size(); f++) {
				if(cmp1[f].fs == cmp2[f].fs) {
					ll u = cmp1[f].sc;
					ll v = cmp2[f].sc;
					bool ok = ((pr[u] == u && pr[v] == v) || (pr[u] == v && pr[v] == u));
					same += ok;
					pr[u] = v;
					pr[v] = u;
				}
			}
		if(same == (int)cmp1.size()) ans.pb(i + 2 - m);
		mmd *= md;
		mmd %= mod;
		mmd2 *= md;
		mmd2 %= mod;
	}

	printf("%d\n", (int)ans.size());
	for(int i = 0; i < (int)ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	return(0);
}

// by Kim Andrey