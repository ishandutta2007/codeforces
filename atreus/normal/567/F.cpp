/**
 *    author:  Atreus
 *    created: 08.02.2019 01:07
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

map<string, string> nott;
ll dp[80][80];
vector<pair<int, string> > g[80];

bool ininterval(int mid, int L, int R){
	if (mid >= L and mid <= R)
		return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	nott["<"] = ">";
	nott[">"] = "<";
	nott["="] = "=";
	nott["<="] = ">=";
	nott[">="] = "<=";
	int n, k;
	cin >> n >> k;
	bool notpossible = 0;
	for (int i = 0; i < k; i++){
		int x, y;
		string sign;
		cin >> x >> sign >> y;
		if (x == y){
			if (sign == ">" or sign == "<")
				notpossible = 1;
		}
		else{
			g[x].push_back({y, sign});
			g[y].push_back({x, nott[sign]});
		}
	}
	if (notpossible)
		return cout << 0 << endl, 0;
	for (int len = 2; len <= 2 * n; len += 2){
		for (int l = 1; l + len - 1 <= 2 * n; l++){
			if (len == 2){
				bool found = 1;
				for (auto e : g[l]){
					if (e.first == l + 1 and (e.second == ">" or e.second == "<"))
						found = 0;
					if (e.first != l + 1 and (e.second == "<" or e.second == "<=" or e.second == "="))
						found = 0;
				}
				dp[l][l + 1] = found;
				continue;
			}
			int r = l + len - 1;
			// both left
			bool found = 1;
			for (auto e : g[l + 1]){
				if (ininterval(e.first, l + 2, r)){
					if (e.second == ">" or e.second == ">=" or e.second == "=")
						found = 0;
				}
				else if (e.first == l){
					if (e.second == ">" or e.second == "<")
						found = 0;
				}
				else{
					if (e.second == "<" or e.second == "<=" or e.second == "=")
						found = 0;
				}
			}
			for (auto e : g[l]){
				if (ininterval(e.first, l + 2, r)){
					if (e.second == ">" or e.second == ">=" or e.second == "=")
						found = 0;
				}
				else if (e.first == l + 1){
					if (e.second == ">" or e.second == "<")
						found = 0;
				}
				else{
					if (e.second == "<" or e.second == "<=" or e.second == "=")
						found = 0;
				}
			}
			dp[l][r] = found * dp[l + 2][r];
			// both right
			found = 1;
			for (auto e : g[r - 1]){
				if (ininterval(e.first, l, r - 2)){
					if (e.second == ">" or e.second == ">=" or e.second == "=")
						found = 0;
				}
				else if (e.first == r){
					if (e.second == ">" or e.second == "<")
						found = 0;
				}
				else{
					if (e.second == "<" or e.second == "<=" or e.second == "=")
						found = 0;
				}
			}
			for (auto e : g[r]){
				if (ininterval(e.first, l, r - 2)){
					if (e.second == ">" or e.second == ">=" or e.second == "=")
						found = 0;
				}
				else if (e.first == r - 1){
					if (e.second == ">" or e.second == "<")
						found = 0;
				}
				else{
					if (e.second == "<" or e.second == "<=" or e.second == "=")
						found = 0;
				}
			}
			dp[l][r] += found * dp[l][r - 2];

			// one left, one right
			found = 1;
			for (auto e : g[l]){
				if (ininterval(e.first, l + 1, r - 1)){
					if (e.second == ">" or e.second == ">=" or e.second == "=")
						found = 0;
				}
				else if (e.first == r){
					if (e.second == ">" or e.second == "<")
						found = 0;
				}
				else{
					if (e.second == "<" or e.second == "<=" or e.second == "=")
						found = 0;
				}
			}
			for (auto e : g[r]){
				if (ininterval(e.first, l + 1, r - 1)){
					if (e.second == ">" or e.second == ">=" or e.second == "=")
						found = 0;
				}
				else if (e.first == l){
					if (e.second == ">" or e.second == "<")
						found = 0;
				}
				else{
					if (e.second == "<" or e.second == "<=" or e.second == "=")
						found = 0;
				}
			}
			dp[l][r] += found * dp[l + 1][r - 1];
		}
	}
	cout << dp[1][2 * n] << endl;
}