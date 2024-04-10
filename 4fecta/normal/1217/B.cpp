#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define d first
#define h second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

ll n, x, a, b;

int main() {
    boost();
    int q;
    cin >> q;
    for (; q > 0; q--) {
        cin >> n >> x;
        ll maxd = 0;
        ll maxo = 0;
        pii hit[n];
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            maxd = max(maxd, a);
            maxo = max(maxo, a - b);
        }
        if (!maxo && maxd < x) {
            printf("-1\n");
            continue;
        } else if (!maxo) {
            printf("1\n");
            continue;
        }
        long double rem = x - maxd;
        ll prelim = max((long double) 0, ceil(rem / (long double) (maxo))) + 1;
        printf("%lld\n", prelim);
    }
    return 0;
}