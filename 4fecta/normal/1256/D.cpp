#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int main() {
    boost();
    int q;
    cin >> q;
    for (; q; q--) {
        ll n, k;
        string s;
        cin >> n >> k >> s;
        int idx = 0;
        for (int i = 0; i < n && k; i++) {
            if (s[i] == '0') {
                int swaps = min(k, (ll) i - idx);
                swap(s[i], s[i - swaps]);
                k -= swaps;
                idx++;
            }
        }
        printf("%s\n", s.c_str());
    }

    return 0;
}