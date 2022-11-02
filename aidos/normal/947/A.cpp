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
int n;
int p[1000100];

int a[1000100];
void solve(){
	cin >> n;
	for(int i = 2; i*i <= n; i++){
		if(!p[i]){
			for(int j = i * i; j <= n; j+=i){
				if(p[j]==0)p[j] = i;
			}
		}
	}
	for(int i = 2; i <= n; i++) if(p[i] == 0) p[i] = i;
	for(int i = 2; i <= n; i++){
		int j = i;
		a[i] = inf;
		while(j > 1){
			int x = p[j];
			while(j % x == 0) {
				j /= x;
			}
			if(x == i) continue;
			int z = i - x+1;
			a[i] = min(a[i], i - x + 1);
		}
	}
	int j = n;
	int ans = inf;
		while(j > 1){
			int x = p[j];
			while(j % x == 0) {
				j /= x;
			}
			for(int i = n - x + 1; i <= n; i++){
				ans = min(a[i], ans);
			}
		}
	cout << ans << endl;
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