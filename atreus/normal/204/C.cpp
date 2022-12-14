#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 500;

vector<int> v[2][26];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < n; i++){
		v[0][int(a[i] - 'A')].push_back(i);
		v[1][int(b[i] - 'A')].push_back(i);
	}

	ll makhraj = 0;
	for (int len = 1; len <= n; len++)
		makhraj += 1ll * (n - len + 1) * (n - len + 1);
	
	ld answer = 0;
	for (int i = 0; i < 26; i++){
		ll pre = 0, suf = 0;
		for (auto j : v[1][i])
			suf += n - j;
		int idx = 0;
		for (auto j : v[0][i]){
			while (idx < v[1][i].size() and v[1][i][idx] < j){
				suf -= n - v[1][i][idx];
				pre += v[1][i][idx] + 1;
				idx ++;
			}
			ll tmp = 1ll * (j + 1) * suf + 1ll * (n - j) * pre;
			answer += 1. * tmp / makhraj;
		}
	}
	cout << fixed << setprecision(6) << answer << endl; 
}