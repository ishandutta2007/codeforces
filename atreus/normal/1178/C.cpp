#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 5;
const int mod = 998244353;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	ll answer = 1;
	for (int i = 1; i <= n + m; i++)
		answer = 2 * answer % mod;
	cout << answer << endl;
}