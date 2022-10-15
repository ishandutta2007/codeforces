#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005;

int n;
string s[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        bool ok = 0;
        set<string> st, cut;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            string tmp = s[i];
            reverse(tmp.begin(), tmp.end());
            if (s[i] == tmp) ok = 1;
            if (tmp.length() >= 2) {
                if (st.count(tmp) || cut.count(tmp)) ok = 1;
                if (st.count(tmp.substr(0, 2))) ok = 1;
                st.insert(s[i]);
                cut.insert(s[i].substr(0, 2));
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}