#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 10;

int par[27][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	for (int j = 0; j < 26; j++)
		for (int i = 1; i <= n; i++)
			par[j][i] = par[j][i - 1] + ((int)(s[i - 1] - 'a') == j);
	int q;
	cin >> q;
	while (q --){
		int l, r;
		cin >> l >> r;
		if (l == r){
			cout << "YES\n";
			continue;
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++)
			if (par[i][r] > par[i][l - 1])
				cnt ++;
		if (cnt > 2 or s[l - 1] != s[r - 1])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}