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
int a[550];
int m;
int b[550];
int dp[550][550];
pii prv[550][550];
pii cur[550];
int h[550];
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			h[j] = -1;
			cur[j]=mp(-1, -1);	
			dp[i][j] = -1;		
		}
		for(int t=0; t<i; t++){
			if(a[i] > a[t]) {
				for(int j =0; j < m; j++){
					if(dp[t][j] > h[j]) {
						h[j] = dp[t][j];
						cur[j] = mp(t, j);
					}
				}			
			}
		}
		int L = 0;
		pii cc = mp(-1, -1);
		for(int j = 0; j < m; j++){
			if(a[i] == b[j]) {
				dp[i][j] = L + 1;
				prv[i][j] = cc;
			}
			if(a[i] > b[j] && L < h[j]) {
				L = h[j];
				cc = cur[j];
			}
		}
	}
	int ans = 0;
	pii cc = mp(-1, -1);
	for(int i = 0;  i < n; i++){
		for(int j =0; j <m;j++){
			if(ans < dp[i][j]){
				ans = dp[i][j];
				cc = mp(i, j);
			}
		}
	}
	cout << ans << "\n";
	vector<int> A;
	for(int i = 0; i < ans; i++){
		pii bb = prv[cc.f][cc.s];
		A.pb(a[cc.f]);
		cc = bb;
	}
	for(int i = 0; i < ans; i++) cout << A[ans-i-1] << " ";
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