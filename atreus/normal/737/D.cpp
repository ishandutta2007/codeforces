#include <bits/stdc++.h>
#define MP make_pair 
using namespace std;
typedef long long ll;
 
const int maxn = 4000 + 10;
const int inf = 1e9;
const int T = 70;

int a[maxn], par[maxn];
int dp[maxn][2 * T + 5][T + 5], pd[maxn][2 * T + 5][T + 5];

inline int sum(int l, int r){
	return par[r] - par[l - 1];
}	

int n;

bool valid(int L, int R){
	return abs((L - 1) - (n - R)) < T;
}

int fd(int L, int R){ // find diff
	return (L - 1) - (n - R) + T;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		par[i] = par[i - 1] + a[i];
	}
	int cnt = 0;
	for (int len = 1; len <= n; len++){
		for (int L = 1; L + len - 1 <= n; L++){
			int R = L + len - 1;
			if (!valid(L, R))
				continue;
			int diff = fd(L, R);
			for (int k = 1; k <= min(len, T); k++){
				int fi = -inf, se = -inf;
				if (valid(L + k, R))
					fi = pd[L + k][fd(L + k, R)][k] + sum(L, L + k - 1);
				if (k + 1 <= len and valid(L + k + 1, R))
					se = pd[L + k + 1][fd(L + k + 1, R)][k + 1] + sum(L, L + k);
				dp[L][diff][k] = max(fi, se);
				
				fi = inf, se = inf;
				if (valid(L, R - k))
					fi = dp[L][fd(L, R - k)][k] - sum(R - k + 1, R);
				if (k + 1 <= len and valid(L, R - k - 1))
					se = dp[L][fd(L, R - k - 1)][k + 1] - sum(R - k, R);
				pd[L][diff][k] = min(fi, se);
			}
		}
	}
	cout << dp[1][fd(1, n)][1] << endl;
}