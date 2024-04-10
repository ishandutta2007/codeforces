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

int x[maxn];
set<int> st;

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

	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		st.insert(x[i]);
	}
	int q;
	scanf("%d", &q);
	for(; q > 0; q--) {
		int z;
		scanf("%d", &z);
		int ans = mod;
		for(int i = 0; i < n; i++) {
			for(int f = 1; f <= k; f++) {
				z -= x[i] * f;
				if(z == 0) {
					ans = min(ans, f);
				}
				if(z > 0)
				for(int g = 1; g + f <= k; g++) {
					if(z % g == 0) {
						if(st.count(z / g)) {
							ans = min(ans, f + g);
							break;
						}
					}
				}
				z += x[i] * f;
			}
		}
		printf("%d\n", ans == mod ? -1 : ans);
	}

	return(0);
}

// by Kim Andrey