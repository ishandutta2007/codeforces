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
const int mod = (int) 1e9 + 7;
using namespace std;
int n;
int a[200200];
pii c[200200];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	n = unique(a, a + n) - a;
	reverse(a, a + n);
	n = min(n, 400);
	int ans=a[0];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n && a[i] + a[j] > ans; j++) {
			if(a[i] % a[j] != 0 && a[j] % a[i] != 0) {
				ans = a[i] + a[j];
			}
		}
	}
	for(int i = 0; i + 2 < n && a[i] + a[i+1] + a[i+2] > ans; i++) {
		for(int j = i+1; j + 1< n && a[i] + a[j] + a[j+1] > ans; j++) {
			if(a[i] % a[j] != 0) {
				for(int k = j + 1; k < n && a[i]+a[j] + a[k] > ans; k++){
					if(a[i] % a[k] != 0 && a[j] % a[k] != 0) {
						ans = a[i] + a[j] + a[k];
					}
				}
			}
		}
	}
	cout << ans << "\n";
}

int main () {
    int t=1;
    scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}