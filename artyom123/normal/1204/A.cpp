#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

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
   	string now = "1";
   	int ans = 0;
   	while (now.size() < s.size() || (now.size() == s.size() && now < s)) {
   		ans++;
   		now += "00";
   	}
   	cout << ans;
    return 0;
}