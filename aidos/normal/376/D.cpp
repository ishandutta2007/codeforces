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

const int inf = (1ll << 25) - 1;
const int maxn = (int)5e3+20;
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
int a[maxn];
char c[maxn][maxn];
int cnt[maxn];
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%s", c[i]);
	}
	int ans = 0;
	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			if(c[i][j] =='1') a[i]++;
			else a[i] = 0;
			cnt[a[i]]++;
		}
		int d = 0;
		for(int k = j + 1; k >= 0; k--) {
			d += cnt[k];
			cnt[k] = 0;
			ans = max(ans, d * k);
		}
	}
	cout << ans << "\n";
}
int main () {
    int t=1;
   	//scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}