#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
const int mod = 998244353;

string get(string s){
	int n = (int)s.size();
	if (n == 0)
		return "";
	vector<int> d1(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	vector<int> d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k ;
		}
	}
	for (int i = 0; i < n; i++){
		d1[i] = 2 * d1[i] - 1;
		d2[i] = 2 * d2[i];
	}
	for (int len = n; len >= 1; len--){
		if (len & 1){
			if (d1[len/2] == len)
				return s.substr(0, len);
			if (d1[n-1 - len/2] == len)
				return s.substr(n - len, len);
		}
		else{
			if (d2[len/2] == len)
				return s.substr(0, len);
			if (d2[n - len/2] == len)
				return s.substr(n - len, len);
		}
	}
}

void solve(){
	string s;
	cin >> s;
	int n = (int)s.size();
	int len = 0;
	for (int i = 0; i < n / 2; i++){
		if (s[i] == s[n-i-1])
			len ++;
		else
			break;
	}
	string t = s.substr(len, n - 2*len);
	string p = get(t);
	string q = s.substr(0, len);
	string r = s.substr(n-len, len);
	cout << (q + p + r) << '\n';
	return;
}	

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}