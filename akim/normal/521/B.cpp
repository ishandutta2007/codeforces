#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
const ll mod = (int)1e+9 + 9;
const double pi = acos(-1.);
const int maxn = 100100;

map<pair<ll, ll>, ll> all;
pair<ll, ll> pa[maxn];
priority_queue<ll> q;
priority_queue<ll> qq;
ll predp[maxn];
bool pm[maxn];

bool opora(int x, int y) {
	if(all.count(mp(x, y))) {
		int cnt = 0;
		if(all.count(mp(x - 1, y - 1))) {
			cnt++;
		}
		if(all.count(mp(x, y - 1))) {
			cnt++;
		}
		if(all.count(mp(x + 1, y - 1))) {
			cnt++;
		}
		return(cnt > 1);
	} else {
		return(1);
	}
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

	ll n;
	cin >> n;
	{
		ll cpm = 1;
		for(ll i = 0; i < n; i++) {
			predp[i] = cpm;
			cpm = (cpm * 1ll * n) % mod;
		}
	}
	for(ll i = 0; i < n; i++) {
		cin >> pa[i].fs >> pa[i].sc;
		all.insert(mp(pa[i], i));
		q.push(i);
		qq.push(-i);
	}
	ll ans = 0;
	for(ll i = 0; i < n; i++) {
		ll nd;
		if(i & 1) {
			while(1) {
				nd = -qq.top(); qq.pop();
				if(pm[nd]) continue;
				if(opora(pa[nd].fs - 1, pa[nd].sc + 1) && opora(pa[nd].fs, pa[nd].sc + 1) && opora(pa[nd].fs + 1, pa[nd].sc + 1)) {
					break;
				}
			}
		} else {
			while(1) {
				nd = q.top(); q.pop();
				if(pm[nd]) continue;
				if(opora(pa[nd].fs - 1, pa[nd].sc + 1) && opora(pa[nd].fs, pa[nd].sc + 1) && opora(pa[nd].fs + 1, pa[nd].sc + 1)) {
					break;
				}
			}
		}
//		cout << nd << endl;
		all.erase(pa[nd]);
		pm[nd] = 1;
		ans += predp[n - i - 1] * 1ll * nd;
		ans %= mod;
		if(all.count(mp(pa[nd].fs - 1, pa[nd].sc - 1))) {
			q.push(all[mp(pa[nd].fs - 1, pa[nd].sc - 1)]);
			qq.push(-all[mp(pa[nd].fs - 1, pa[nd].sc - 1)]);
		}
		if(all.count(mp(pa[nd].fs, pa[nd].sc - 1))) {
			q.push(all[mp(pa[nd].fs, pa[nd].sc - 1)]);
			qq.push(-all[mp(pa[nd].fs, pa[nd].sc - 1)]);
		}
		if(all.count(mp(pa[nd].fs + 1, pa[nd].sc - 1))) {
			q.push(all[mp(pa[nd].fs + 1, pa[nd].sc - 1)]);
			qq.push(-all[mp(pa[nd].fs + 1, pa[nd].sc - 1)]);
		}
	}

	cout << ans;

	return(0);
}

// by Kim Andrey