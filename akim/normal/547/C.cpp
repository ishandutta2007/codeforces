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
const int maxn = 500100;

int rw[maxn];
int a[maxn];
bool used[maxn];
int kol[maxn];
int inuse;
ll ans;

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

	for(int i = 2; i < maxn; i++) {
		if(rw[i] == 0) {
			for(int f = i; f < maxn; f += i) {
				rw[f] = i;
			}
		}
	}

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i + 1]);
	}
	for(int i = 0; i < m; i++) {
		int u;
		scanf("%d", &u);
		if(!used[u]) {
			used[u] = 1;
			u = a[u];
			vector<int> vc;
			while(u > 1) {
				if(vc.empty() || vc.back() != rw[u]) vc.pb(rw[u]);
				u /= rw[u];
			}
//			for(int i = 0; i < vc.size(); i++) {
//				cout << vc[i] << " ";
//			}cout << "--" << endl;
			int maxmask = (1 << vc.size());
			for(int mask = 1; mask < maxmask; mask++) {
				int cnt = 0, val = 1;
				for(int f = 0; f < (int)vc.size(); f++) {
					if((mask >> f) & 1) {
						cnt++;
						val *= vc[f];
					}
				}
				if(cnt & 1) {
					ans += kol[val];
				} else {
					ans -= kol[val];
				}
				kol[val]++;
			}
			inuse++;
			printf("%I64d\n", ((inuse * 1ll * (inuse - 1)) >> 1) - ans);
		} else {
			used[u] = 0;
			u = a[u];
			vector<int> vc;
			while(u > 1) {
				if(vc.empty() || vc.back() != rw[u]) vc.pb(rw[u]);
				u /= rw[u];
			}
			int maxmask = (1 << vc.size());
			for(int mask = 1; mask < maxmask; mask++) {
				int cnt = 0, val = 1;
				for(int f = 0; f < (int)vc.size(); f++) {
					if((mask >> f) & 1) {
						cnt++;
						val *= vc[f];
					}
				}
				kol[val]--;
				if(cnt & 1) {
					ans -= kol[val];
				} else {
					ans += kol[val];
				}
			}
			inuse--;
			printf("%I64d\n", ((inuse * 1ll * (inuse - 1)) >> 1) - ans);
		}
	}

	return(0);
}

// by Kim Andrey