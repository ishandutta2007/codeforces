/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

	int n, m;
	cin >> n >> m;

	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar, ar + n);

	map<string, int> mp;
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		mp[s]++;
	}

	vector<int> v;
	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
		v.push_back(it->second);
	}
	sort(v.begin(), v.end());

	ll ans = 0;
	for(int i = 0; i < v.size(); i++)
		ans += ar[i] * v[v.size() - i - 1];

	cout << ans << " ";
	ans = 0;

	for(int i = 0; i < v.size(); i++)
		ans += ar[n - i - 1] * v[v.size() - i - 1];

	cout << ans;

}