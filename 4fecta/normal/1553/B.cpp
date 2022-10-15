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
        string s, t;
        cin >> s >> t;
        bool ok = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int r = i; r < s.size(); r++) {
                string tmp;
                for (int p = i; p <= r; p++) tmp += s[p];
                int ptr = r - 1;
                while (ptr >= 0 && tmp.size() < t.size()) tmp += s[ptr--];
                if (tmp == t) ok = 1;
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}