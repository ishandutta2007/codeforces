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
int a[1231];
int dp[123];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	for(int i = 0; i <= 100; i++) {
		for(int j = 0; j < n; j++) {
			if(a[j] < i) dp[i] += i-1-a[j];
			else if(a[j] > i) dp[i] += a[j] - i - 1;
		}
	}
	int c = 1;
	for(int i = 0; i <= 100; i++) if(dp[c] > dp[i]) c=i;
	cout << c << " "<< dp[c] << "\n";
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