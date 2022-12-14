#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int a[maxn], b[maxn], dp[maxn];
map<int,int> last;
ll answer;

void solve(int n, int m){
	last.clear();
	for (int i = 1; i <= m; i++)
		a[i] -= i;
	for (int i = m; i >= 1; i--){
		if (last.count(a[i]-1))
			dp[i] = dp[last[a[i]-1]] + 1;
		else
			dp[i] = 1;
		last[a[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		int t = (m + 1) - dp[last[i]];
		answer += min(n - i, t) + 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> b[i];
		a[i] = b[i];
	}
	if (n == 1)
		return cout << 0 << endl, 0;
	solve(n, m);
	reverse(b + 1, b + m + 1);
	for (int i = 1; i <= m; i++)
		a[i] = b[i];
	solve(n, m);
	answer -= n;
	cout << answer << endl;
}