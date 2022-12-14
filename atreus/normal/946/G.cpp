#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
int a[maxn];

int dp[2][maxn], fen[2][2 * maxn];

void add(bool w, int idx, int val){
	for (; idx < 2 * maxn; idx += idx & -idx)
		fen[w][idx] = max(fen[w][idx], val);
}

int get(bool w, int idx){
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret = max(ret, fen[w][idx]);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> cmp;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		a[i] -= i;
		cmp.push_back(a[i]);
		cmp.push_back(a[i] + 1);
	}
	sort(cmp.begin(), cmp.end());
	cmp.resize(unique(cmp.begin(), cmp.end()) - cmp.begin());
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin() + 1;
	int answer = n;
	for (int i = 0; i < n; i++){
		dp[0][i] = get(0, a[i]) + 1;
		dp[1][i] = max(dp[1][i], get(1, a[i]) + 1);
		dp[1][i + 1] = get(0, a[i + 1] + 1) + 1;
		add(0, a[i], dp[0][i]);
		add(1, a[i], dp[1][i]);
		answer = min(answer, n - dp[1][i] - 1);
	}
	cout << max(answer, 0) << endl;
}