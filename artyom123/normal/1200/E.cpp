#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const long long mod = 1e9 + 7;
const int MAXN = 1e6 + 10;
const long long p = 101;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
   	int n;
   	cin >> n;
   	string ans = "";
   	vector <long long> h;
   	vector <long long> my_pow(MAXN);
   	my_pow[0] = 1;
   	for (int i = 1; i < MAXN; i++) {
   		my_pow[i] = (my_pow[i - 1] * p) % mod;
   	}
   	h.pb(0);
   	for (int i = 0; i < n; i++) {
   		string s;	
   		cin >> s;
   		vector <int> now_h(s.size() + 1);
   		for (int j = 0; j < s.size(); j++) {
   			now_h[j + 1] = (now_h[j] * p + s[j]) % mod;
   		}
   		int j = 1;
   		int max_j = 0;
   		for (; j <= s.size() && j <= ans.size(); j++) {
   			if ((h.back() - h[ans.size() - j] * my_pow[j] + mod * mod) % mod == now_h[j]) {
   				max_j = j;
   			}
   		}
   		for (int k = max_j; k < s.size(); k++) {
   			ans.pb(s[k]);
   			h.pb((h.back() * p + ans.back()) % mod);
   		}
   	}
   	cout << ans;
    return 0;
}