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
int n, m, k;
int pre[100100];

int last[100100];
int ans[100100];
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0, x; j < m; j++){
			scanf("%d", &x);
			if(i>0 && last[j]<= x){
				
			}
			else pre[j] = i;
			last[j] = x;
		}
		ans[i] = i;
		for(int j = 0; j < m; j++)
			ans[i] = min(ans[i], pre[j]);
	}
	scanf("%d", &k);
	for(int i = 0, l, r; i < k; i++){
		scanf("%d%d", &l, &r);
		if(ans[r-1] <= l-1){
			printf("Yes\n");
		}
		else printf("No\n");
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