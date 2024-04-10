#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, a[MN], b[MN], cnt[MN];

int32_t main() {
    boost();

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        bool ok = 1;
        int i = n, j = n;
        while (i > 0) {
            while (b[i] != a[j]) {
                if (cnt[a[j]]) cnt[a[j]]--, j--;
                else {ok = 0; goto done;}
            }
            i--, j--;
            while (i > 0 && b[i] == b[i + 1]) {
                if (a[j] == b[i]) j--;
                else cnt[b[i]]++;
                i--;
            }
        }
        done:
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}