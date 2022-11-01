#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int calc(string a, string b) {
	int n = a.size();
	for(int i = 0; i < n; i++)
		if(a[i] != '?' && b[i] != '?' && a[i] > b[i])
			return 0;
	int res = 1;
	for(int i = 0; i < n; i++)
		if(isdigit(a[i]) && isdigit(b[i]))
			continue;
		else if(isdigit(b[i]))
			res = (1LL * res * (b[i] - '0' + 1)) % mod;
		else if(isdigit(a[i]))
			res = (1LL * res * ('9' - a[i] + 1)) % mod;
		else
			res = (55LL * res) % mod;
	return res;
}

int equal(string a, string b) {
	int n = a.size();
	for(int i = 0; i < n; i++)
		if(isdigit(a[i]) && isdigit(b[i]) && a[i] != b[i])
			return 0;
	int res = 1;
	for(int i = 0; i < n; i++)
		if(isdigit(a[i]) || isdigit(b[i]))
			continue;
		else
			res = (10LL * res) % mod;
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	string a, b;
	cin >> n >> a >> b;
	int cnt = 0;
	for(char ch : a)
		cnt += (ch == '?');
	for(char ch : b)
		cnt += (ch == '?');
	int ans = 1;
	for(int i = 0; i < cnt; i++)
		ans = (10LL * ans) % mod;
	ans = ((long long)ans - calc(a, b) - calc(b, a) + mod + mod + equal(a, b)) % mod;
	cout << ans;
}