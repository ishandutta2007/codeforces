#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, q;
string a, b;

int find(char c, string s) {
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == c) return i;
    }
    return -1;
}

int main() {
    boost();
    cin >> q;
    while (q--) {
        cin >> n >> a >> b;
        vector<pii > swaps;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            int idx = find(a[i], b);
            if (idx < i) {
                idx = find(a[i], a);
                if (idx <= i) {
                    printf("No\n");
                    goto done;
                }
                swap(b[i], a[idx]);
                swaps.push_back({idx, i});
            } else {
                swap(a[idx], b[idx]);
                swaps.push_back({idx, idx});
                swap(a[idx], b[i]);
                swaps.push_back({idx, i});
            }
        }
        printf("Yes\n%d\n", swaps.size());
        for (pii p : swaps) {
            printf("%d %d\n", p.f + 1, p.s + 1);
        }
        done: n = 69;
    }

    return 0;
}