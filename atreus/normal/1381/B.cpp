#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4000 + 10;

int p[maxn], a[maxn];
bool dp[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc--){
		int n;
		cin >> n;
		for (int i = 1; i <= 2*n; i++){
			int x;
			cin >> x;
			p[x] = i;
		}
		int sz = 0;
		int mnm = 2*n+1;
		for (int i = 2*n; i >= 1; i--){
			if (p[i] >= mnm)
				continue;
			a[++sz] = mnm - p[i];
			mnm = p[i];
		}
		dp[0][0] = 1;
		for (int i = 1; i <= sz; i++)
			for (int j = 0; j <= n; j++){
				dp[i][j] = dp[i-1][j];
				if (j >= a[i])
					dp[i][j] = (dp[i-1][j] | dp[i-1][j-a[i]]);
			}
		if (dp[sz][n])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}