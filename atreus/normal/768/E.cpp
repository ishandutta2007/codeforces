#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1026;
const int mod = 998244353;

map<ll,short> dp[62];
bool mark[62];

int f(int x, ll mask){
	if (dp[x].count(mask))
		return dp[x][mask];
	if (x == 0)
		return 0;
	vector<bool> mark(61);
	for (int j = 0; j <= 60; j++)
		mark[j] = false;
	for (int j = 1; j <= x; j++){
		if (mask & (1ll << j))
			continue;
		mark[f(x-j, mask ^ (1ll << j))] = true;
	}
	for (int i = 0; i <= 60; i++){
		if (mark[i] == false){
			dp[x][mask] = i;
			break;
		}
	}
	return dp[x][mask];
}

int main(){
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 60; i++)
		f(i, 0);
	int n;
	cin >> n;
	int x = 0;
	for (int i = 1; i <= n; i++){
		int y;
		cin >> y;
		x ^= dp[y][0];
	}
	if (x == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
}