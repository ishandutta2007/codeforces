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
   	int cnt = 0, max0 = 0, max1 = 0;
   	string ans = "";
   	for (int i = 0; i < s.size(); i++) {
   		ans.pb('0');
   	}
   	for (int i = s.size() - 1; i >= 0; i--) {
   		if (s[i] == '1' && cnt < max(max0, max1)) {
   			ans[i] = '1';
   		}
   		cnt += s[i] - '0';
   		if (s[i] == '0') {
   			max0 = max(max0 + 1, max1 + 1);
   		} else {
   			max1++;
   		}
   	}
   	cout << ans;
    return 0;
}