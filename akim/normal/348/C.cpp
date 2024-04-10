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

const int sq = 250;

ll a[maxn];
int nbig;
vector<int> vc[maxn];
int ssl[maxn], cntinc[sq];
bool pm[sq][maxn];
int peres[sq][maxn];
ll sum[sq];
ll inc[sq];

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

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
	}
	for(int i = 0; i < m; i++) {
		int sz;
		scanf("%d", &sz);
		bool big = (sz > sq);
		ssl[i] = nbig;
		for(int f = 0; f < sz; f++) {
			vc[i].pb(0);
			scanf("%d", &vc[i].back());
			vc[i].back()--;
			if(big) {
				pm[nbig][vc[i].back()] = 1;
				sum[nbig] += a[vc[i].back()];
			}
		}
		nbig += big;
	}

	for(int i = 0; i < nbig; i++) {
		for(int f = 0; f < m; f++) {
			for(int g = 0; g < (int)vc[f].size(); g++) {
				peres[i][f] += pm[i][vc[f][g]];
			}
		}
	}

	for(; q > 0; q--) {
		char zp;
		cin >> zp;
		if(zp == '+') {
			int num, val;
			scanf("%d%d", &num, &val);
			num--;
			if(vc[num].size() > sq) {
				inc[ssl[num]] += val;
			} else {
				for(int i = 0; i < (int)vc[num].size(); i++) {
					a[vc[num][i]] += val;
				}
				for(int i = 0; i < nbig; i++) {
					sum[i] += peres[i][num] * val;
				}
			}
		} else {
			int num;
			scanf("%d", &num);
			num--;
			ll ans = 0;
			if(vc[num].size() > sq) {
				ans = sum[ssl[num]];
			} else {
				for(int i = 0; i < (int)vc[num].size(); i++) {
					ans += a[vc[num][i]];
				}
			}
			for(int i = 0; i < nbig; i++) {
				ans += inc[i] * peres[i][num];
			}
			printf("%I64d\n", ans);
		}
	}

	return(0);
}

// by Kim Andrey