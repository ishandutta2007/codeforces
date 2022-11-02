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
int n, k;
ll dp[200200];
int a[200200];
void solve(){
	scanf("%d%d", &n, &k);
	ll d = 0;
	for(int i = 1; i <= k; i++) {
		dp[i] = dp[i-1] + i;
		d += i;
		a[i] = i;
	}
	if(d > n) {
		printf("No\n");
		return;
	}
	d = (n-dp[k])/k;
	for(int i = 1; i <= k; i++) {
		a[i] += d;
		n -= a[i];
	}
	int cnt = 0;
	while(n>0 && cnt < 120){
		for(int i = k; i > 0; i--){
			if(i == k) {
				int x = min(n, a[i-1] * 2 - a[i]);
				a[i] += x;
				n-=x;	
			}else if(i == 1) {
				int x = min(n, a[i+1] - a[i] - 1);
				a[i] += x;
				n-=x;	
			}else {
				int x = min(n, min(a[i+1]-a[i]-1, 2 * a[i-1] - a[i]));
				a[i] += x;
				n-=x;
			}
		}
		cnt++;
	}
	if(n > 0) {
		printf("No\n");
		return;
	}
	printf("Yes\n");
	for(int i = 1; i <= k; i++) printf("%d ", a[i]);	
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