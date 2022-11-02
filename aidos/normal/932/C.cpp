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
int n, a, b;
int p[1001000];

void out(int x, int y){
	int j = 1;
	for(int i = 0; i < x; i++){
		int k = j + a - 1;
		for(int t = j + 1; t <= k; t++){
			p[t-1] = t;
		}
		p[k] = j;
		j += a;
	}
	for(int i = 0; i < y; i++){
		int k = j + b - 1;
		for(int t = j + 1; t <= k; t++){
			p[t-1] = t;
		}
		p[k] = j;
		j += b;
	}
	for(int i = 1; i <= n; i++){
		printf("%d ", p[i]);
	}
	exit(0);
}
void solve(){
	cin >> n >> a >> b;
	for(int i = 0; i <= n; i++){
		ll cur = i * 1ll * a;
		if(cur>n) continue;
		if((n-cur) % b == 0){
			out(i, (n-cur)/b);
		}
	}
	printf("-1\n");
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