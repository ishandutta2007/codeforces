#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;

int sum[11][1001000];
int g[1001000];
void solve(){
	
	for(int i = 1; i <= 1000100; i++){
		if(i < 10) g[i] = i;
		else {
			int j = i;
			int k = 1;
			while(j > 0){
				if(j % 10) k *= j % 10;
				j/=10;
			}
			g[i] = g[k];
		}
		for(int j = 1; j < 10; j++){
			sum[j][i] = sum[j][i-1];
		}
		sum[g[i]][i]++;
	}
	int q;
	scanf("%d", &q);
	for(int i = 0, l, r, k; i < q; i++){
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", sum[k][r] - sum[k][l-1]);
	}
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}