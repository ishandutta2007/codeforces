#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
   	string s;
   	cin >> s;
   	string ans = "";
   	int n = s.size();
   	for (int i = 0; i < n; i++) {
   		ans.pb('0');
   	}
   	for (int i = 0; i < n - 1; i++) {
   		if (s[i] == '0') {
   			continue;
   		}
   		int cnt_one = 0;
   		int best_zero = 0;
   		int best_one = 0;
   		for (int j = i + 1; j < n; j++) {
   			cnt_one += s[j] - '0';
   			if (s[j] == '0') {
   				best_zero++;
   			} else {
   				best_one = max(best_one + 1, best_zero + 1);
   			}
   		}
   		if (cnt_one < max(best_one, best_zero)) {
   			ans[i] = '1';
   		}
   	}
   	cout << ans;
    return 0;
}