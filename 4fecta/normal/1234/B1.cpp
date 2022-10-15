#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, k, m;

int main() {
    boost();

    set<int> has;
    int q[200005];
    int l = 0, r = 0;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m;
        if (has.count(m)) continue;
        q[r++] = m;
        has.insert(m);
        if (r - l > k) {
            has.erase(q[l++]);
        }
    }

    printf("%d\n", r - l);
    while (r ^ l) printf("%d ", q[--r]);
    printf("\n");

    return 0;
}