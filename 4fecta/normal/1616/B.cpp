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

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int id = n - 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] > s[i - 1]) {
                id = i - 1;
                break;
            }
        }
        string t1;
        for (int i = 0; i <= id; i++) t1 += s[i];
        for (int i = id; i >= 0; i--) t1 += s[i];
        string t2;
        t2 += s[0];
        t2 += s[0];
        if (t1 < t2) printf("%s\n", t1.c_str());
        else printf("%s\n", t2.c_str());

    }

    return 0;
}