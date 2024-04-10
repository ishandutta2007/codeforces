#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 4000 + 10;
const int inf = 2e9;

int dp[maxn][maxn];
vector<int> vec[28];
int last[28], last2[28];

int g(char c){
	return (int)(c - 'a');
}

int get(char z){
	return last2[g(z)];
}

int main(){
	ios_base::sync_with_stdio(false);
	int ti, td, tr, ts;
	cin >> ti >> td >> tr >> ts;
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	s = " " + s;
	t = " " + t;
	for (int i = 1; i <= m; i++)
		vec[(int)(t[i] - 'a')].push_back(i);
	memset(dp, 63, sizeof dp);
	for (int i = 1; i <= n; i++)
		dp[i][0] = i * td;
	for (int i = 1; i <= m; i++)
		dp[0][i] = i * ti;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++){
		last[g(s[i])] = i;
		memset(last2, -1, sizeof last2);
		for (int j = 1; j <= m; j++){
			last2[g(t[j])] = j;
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + td); // just erase last one
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + ti); // just insert last one
			if (s[i] == t[j])
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]); // it is already matched
			dp[i][j] = min(dp[i][j], dp[i-1][j-1] + tr); // replace last one
			if (i > 1 and j > 1 and s[i] != t[j]){ // i is going to swap but not replace
				int j1 = get(s[i]);
				if (j1 != -1)
					dp[i][j] = min(dp[i][j], dp[i-2][j1-1] + ts + tr + (j-j1-1) * ti);
				if (j1 != -1 and last[g(t[j])]){
					int i1 = last[g(t[j])];
					dp[i][j] = min(dp[i][j], dp[i1-1][j1-1] + (i-i1-1) * td + (j-j1-1) * ti + ts);
				}
			}
/*			if (i > 1 and j > 1 and s[i] != t[j] and last[g(t[j])]){ // i is going to swap and replace
				char bef = s[i];
				int i1 = last[g(t[j])];
				for (char z = 'a'; z <= 'z'; z++){
					int j1 = get(z);
					if (j1 == -1)
						continue;
					dp[i][j] = min(dp[i][j], dp[i1-1][j1-1] + (i-i1-1) * td + (j-j1-1) * ti + ts + tr);
				}
			}
*/		}
	}
	cout << dp[n][m] << endl;
}