/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

	ll n;
	cin >> n;
	string s[n];
	ll c[n], ans = 0;
	map<string, ll> m, m2;

	for(int i = 0; i < n; i++){
		cin >> s[i] >> c[i];
		m[s[i]] += c[i];
	}

	for(map<string, ll>::iterator it = m.begin(); it != m.end(); it++){
		ll g = it->second;
		if(g > ans){
			m2.clear();
			ans = g;
		}
		if(g == ans)
			m2[it->first]++;
	}

	m.clear();

	for(int i = 0; i < n; i++){
		m[s[i]] += c[i];
		if(m[s[i]] >= ans && m2.count(s[i]) != 0){
			cout << s[i] << endl;
			return 0;
		}
	}

}