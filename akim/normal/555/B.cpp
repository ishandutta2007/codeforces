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
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const ll mod = (ll)1e+9 + 7;
const double pi = acos(-1.);
const ll maxn = 2 * 100100;

ll ans[maxn];
ll lef[maxn];
pair<ll, ll> deo[12 * maxn];
vector<pair<ll, pair<ll, ll> > > vc;

void change(ll pos, pair<ll, ll> val, ll v = 0, ll tl = 0, ll tr = 3 * maxn - 1) {
	if(tl == tr) {
		deo[v] = val;
		return;
	}
	ll tm = (tl + tr) >> 1;
	if(pos <= tm) {
		change(pos, val, v * 2 + 1, tl, tm);
	} else
	{
		change(pos, val, v * 2 + 2, tm + 1, tr);
	}
	deo[v] = min(deo[v * 2 + 1], deo[v * 2 + 2]);
}

pair<ll, ll> getmin(ll lf, ll rg, ll v = 0, ll tl = 0, ll tr = 3 * maxn - 1) {
	if(lf > rg) {
		return(mp(mod, mod));
	}
	if(tl == lf && tr == rg) {
		return(deo[v]);
	}
	ll tm = (tl + tr) >> 1;
	return(min(getmin(lf, min(rg, tm), v * 2 + 1, tl, tm), getmin(max(lf, tm + 1), rg, v * 2 + 2, tm + 1, tr)));
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	ll n, m;
	scanf("%I64d%I64d", &n, &m);
	ll l, r;
	scanf("%I64d%I64d", &l ,&r);
	for(ll i = 1; i < n; i++) {
		ll l1, r1;
		scanf("%I64d%I64d", &l1 ,&r1);
		vc.pb(mp(l1 - r, mp(-1, i)));
		vc.pb(mp(r1 - l, mp(1, i)));
		l = l1, r = r1;
	}
	for(ll i = 1; i <= m; i++) {
		ll len;
		scanf("%I64d", &len);
		vc.pb(mp(len, mp(0, i)));
	}

	sort(vc.begin(), vc.end());

	for(ll i = 0; i < (ll)vc.size(); i++) {
		if(vc[i].sc.fs == 0) {
			change(i, mp(i, vc[i].sc.sc));
		} else {
			change(i, mp(mod, mod));
			if(vc[i].sc.fs == -1) {
				lef[vc[i].sc.sc] = i;
			} else {
				pair<ll, ll> p = getmin(lef[vc[i].sc.sc], i);
				if(p.fs == mod) {
					printf("No\n");
					return(0);
				} else {
					ans[vc[i].sc.sc] = p.sc;
					change(p.fs, mp(mod, mod));
				}
			}
		}
	}

	printf("Yes\n");
	for(ll i = 1; i < n; i++) {
		printf("%I64d ", ans[i]);
	}

	return(0);
}

// by Kim Andrey