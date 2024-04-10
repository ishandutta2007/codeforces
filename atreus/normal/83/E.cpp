#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

int n, m;
int a[maxn], dp[maxn];
int pd[21][(1 << 20) + 10];

int cost(int fi, int se){
	for (int i = m; i >= 1; i--){
		int cfi = fi % (1 << i);
		int cse = (se >> (m - i));
		if (cfi == cse){
//			cout << fi << " " << se << " -> " << i << endl;
			return m - i;
		}
	}
	return m;
}

void add(int k, int v){
	for (int i = m; i >= 0; i--){
		int u = v % (1 << i);
		pd[i][u] = min(pd[i][u], k);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		m = s.size();
		for (int j = m - 1; j >= 0; j--)
			if (s[j] == '1')
				a[i] += (1 << (m - j - 1));
	}
	if (n == 1)
		return cout << m << endl, 0;
	int lazy = 0;
	memset(dp, 63, sizeof dp);
	memset(pd, 63, sizeof pd);
	dp[0] = m;
	dp[1] = 2 * m;
	lazy = cost(a[0], a[1]);
	add(dp[1] - lazy, a[0]);
	for (int i = 2; i < n; i++){
		for (int j = m; j >= 0; j--)
			dp[i] = min(dp[i], pd[j][(a[i] >> (m - j))] + lazy + (m - j));
		dp[i] = min(dp[i], lazy + 2 * m);
		lazy += cost(a[i - 1], a[i]);
		add(dp[i] - lazy, a[i - 1]);
	}

	int answer = 0;
	for (int i = 0; i < n - 1; i++)
		answer += cost(a[i], a[i + 1]);
	answer += m;
	
	int now = 0;
	for (int i = n - 1; i >= 1; i--){
		answer = min(answer, now + dp[i]);
		now += cost(a[i - 1], a[i]);
	}
	
	cout << answer << endl;
}