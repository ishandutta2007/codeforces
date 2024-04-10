#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;

ll dp[30][30], cnt[30];

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++){
		int c = (int)(s[i] - 'a');
		for (int i = 0; i < 26; i++)
			dp[i][c] += cnt[i];
		cnt[c] ++;
	}
	ll answer = 0;
	for (int i = 0; i < 26; i++){
		answer = max(answer, cnt[i]);
		for (int j = 0; j < 26; j++)
			answer = max(answer, dp[i][j]);
	}
	cout << answer << '\n';
}