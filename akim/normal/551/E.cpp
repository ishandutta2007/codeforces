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
const int maxn = 100100;

vector<pair<ll, int> > st[maxn];
ll add[maxn];

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

	int n, q;
	scanf("%d%d", &n, &q);
	int sz = 1200, cnt = 0;
	for(int i = 0; i < n; i++) {
		if((int)st[cnt].size() == sz) {
			cnt++;
		}
		st[cnt].pb(mp(0, i));
		scanf("%I64d", &st[cnt].back().fs);
	}
	if(!st[cnt].empty()) {
		cnt++;
	}
	for(int i = 0; i < cnt; i++) {
		sort(st[i].begin(), st[i].end());
	}
	for(; q > 0; q--) {
		int tp;
		scanf("%d", &tp);
		if(tp == 1) {
			int l, r;
			ll x;
			scanf("%d%d%I64d", &l, &r, &x);
			l--, r--;
			int sl = 0, sr = - 1;
			for(int i = 0; i < cnt; i++) {
				sl = sr + 1;
				sr += st[i].size();
				if(sr < l || sl > r) {
					continue;
				}
				if(l <= sl && sr <= r) {
					add[i] += x;
					continue;
				}
				for(int f = 0; f < (int)st[i].size(); f++) {
					if(st[i][f].sc >= l && st[i][f].sc <= r) {
						st[i][f].fs += x;
					}
				}
				sort(st[i].begin(), st[i].end());
			}
		} else {
			ll y;
			scanf("%I64d", &y);
			int l = mod, r = -mod;
			bool ok = 0;
			for(int i = 0; i < cnt; i++) {
				int pos = lower_bound(st[i].begin(), st[i].end(), mp(y - add[i], 0)) - st[i].begin();
				if(pos < (int)st[i].size() && st[i][pos].fs == y - add[i]) {
					l = st[i][pos].sc;
					ok = 1;
					break;
				}
			}
			for(int i = cnt - 1; i >= 0; i--) {
				int pos = lower_bound(st[i].begin(), st[i].end(), mp(y - add[i], mod)) - st[i].begin();
				pos--;
				if(pos >= 0 && st[i][pos].fs == y - add[i]) {
					r = st[i][pos].sc;
					ok = 1;
					break;
				}
			}
			if(ok) {
				printf("%d\n", r - l);
			} else {
				printf("-1\n");
			}
		}
	}


	return(0);
}

// by Kim Andrey