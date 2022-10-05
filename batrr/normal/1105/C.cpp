#include <bits/stdc++.h>                                                                                                                                                                                      //YaLoh

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

ll n, l, r, cnt[3], dp[N][3];
void get(int n, int k){
	while(n % 3 != 0)
		cnt[n % 3] += k, n--;
	for(int i = 0; i < 3; i++)
		cnt[i] += n / 3 * k;
}
int main(){
	cin >> n >> l >> r;
	get(r, 1);
	get(l - 1, -1);
	for(int i = 0; i < 3; i++)
		cerr << cnt[i] << " ";cerr << endl;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 3; j++)
			for(int q = 0; q < 3; q++)
				dp[i][(j + q) % 3] = (dp[i][(j + q) % 3] +  dp[i - 1][j] * cnt[q])  % mod;
	cout << dp[n][0];
	return 0;
}