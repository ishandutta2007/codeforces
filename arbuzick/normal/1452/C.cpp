#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 0;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                cnt1++;
            else if (s[i] == '[')
                cnt2++;
            else if (s[i] == ')' && cnt1)
                ans++, cnt1--;
            else if (s[i] == ']' && cnt2)
                ans++, cnt2--;
        }
        cout << ans << '\n';
    }
    return 0;
}