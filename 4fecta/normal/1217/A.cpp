#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int s, i, e;

int main() {
    boost();

    int q;
    cin >> q;
    for (; q > 0; q--) {

        cin >> s >> i >> e;
        if (s + e <= i) {printf("0\n"); continue;}
        int lo = 0, hi = e, mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            int ip = e - mid;
            if (s + mid > i + ip) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        printf("%d\n", e - lo + 1);
    }

    return 0;
}