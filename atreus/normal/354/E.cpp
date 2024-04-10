#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e6 + 10;

int dp[25][10];
int a[25];
ll b[8];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		ll n;
		cin >> n;
		int x = 0;
		for (int i = 0; i < 19; i++)
			a[i] = 0;
		while (n){
			a[x++] = n % 10;
			n /= 10;
		}
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for (int d = 0; d < 19; d++){
			for (int i = 0; i <= 4; i++){
				if (dp[d][i] == 0)
					continue;
				for (int j = 0; j <= 6; j++){
					for (int k = 0; j+k <= 6; k++){
						int sum = i + 4*j + 7*k;
						if (sum % 10 != a[d])
							continue;
						dp[d+1][sum/10] = 1;
					}
				}
			}
		}
		if (dp[19][0] == 0){
			cout << -1 << '\n';
			continue;
		}
		int d = 19, sum = 0;
		for (int i = 0; i < 6; i++)
			b[i] = 0;
		while (d > 0){
			d --;
			ll pw = 1;
			for (int i = 1; i <= d; i++)
				pw *= 10;
			bool found = 1;
			for (int i = 0; found and i <= 4; i++){
				if (dp[d][i] == 0)
					continue;
				for (int j = 0; found and j <= 6; j++){
					for (int k = 0; found and j+k <= 6; k++){
						int now = i + 4*j + 7*k;
						if (now % 10 != a[d] or now/10 != sum)
							continue;
						found = 0;
						for (int x = 0; x < j; x++)
							b[x] += 4ll * pw;
						for (int x = j; x < j+k; x++)
							b[x] += 7ll * pw;
						sum = i;
					}
				}
			}
		}
		for (int i = 0; i < 6; i++)
			cout << b[i] << " ";
		cout << '\n';
	}
}