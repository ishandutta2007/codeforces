#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int32_t main() {
    boost();

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int ans = 10;
        int cnt1 = 0, cnt2 = 0, rem1 = 5, rem2 = 5;
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                if (s[i] != '0') cnt1++;
                rem1--;
                if (cnt1 > cnt2 + rem2) {ans = min(ans, i + 1); break;}
            } else {
                if (s[i] == '1') cnt2++;
                rem2--;
                if (cnt1 > cnt2 + rem2) {ans = min(ans, i + 1); break;}
            }
        }
        cnt1 = cnt2 = 0;
        rem1 = rem2 = 5;
        for (int i = 0; i < 10; i++) {
            if (i % 2) {
                if (s[i] != '0') cnt1++;
                rem1--;
                if (cnt1 > cnt2 + rem2) {ans = min(ans, i + 1); break;}
            } else {
                if (s[i] == '1') cnt2++;
                rem2--;
                if (cnt1 > cnt2 + rem2) {ans = min(ans, i + 1); break;}
            }
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}