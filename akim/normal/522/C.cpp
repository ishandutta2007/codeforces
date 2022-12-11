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
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int cnt[maxn];
bool ans[maxn];
int bludo[maxn], ok[maxn];
bool used[maxn];

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

	int T;
	scanf("%d", &T);
	for(; T > 0; T--) {
		int m, k;
		scanf("%d%d", &m, &k); m--;
		for(int i = 0; i < k; i++) {
			scanf("%d", &cnt[i]);
		}
		bool kill = 0;
		for(int i = 0; i < m; i++) {
			scanf("%d%d", &bludo[i], &ok[i]);
			if(ok[i]) {
				kill = 1;
			}
			if(kill) {
				used[bludo[i] - 1] = 1;
			}
		}
		kill = 0;
		int empty = 0;
		for(int i = 0; i < m; i++) {
			if(ok[i] && (!kill)) {
				kill = 1;
				int minn = mod;
				for(int f = 0; f < k; f++) {
					if(cnt[f] <= empty && (!used[f])) {
						ans[f] = 1;
					}
					if(!used[f]) minn = min(minn, cnt[f]);
				}
				empty -= minn;
			}
			if(bludo[i] != 0) {
				cnt[bludo[i] - 1]--;
			} else {
				empty++;
			}
		}
		for(int i = 0; i < k; i++) {
			if(cnt[i] <= empty) {
				ans[i] = 1;
			}
		}
		for(int i = 0; i < k; i++) {
			if(ans[i] == 1) {
				printf("Y");
			} else {
				printf("N");
			}
			ans[i] = 0;
			used[i] = 0;
		}
		printf("\n");
	}

	return(0);
}

// by Kim Andrey