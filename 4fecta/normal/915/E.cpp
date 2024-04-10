#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int main() {
    boost();
    
    int n, q;
    cin >> n >> q;
    set<pii> s;
    s.insert({0, n});
    int cnt = n;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        while (true) {
            auto it = s.lower_bound({l, -1});
            if (it == s.end()) break;
            pii p = *it;
            if (p.f >= r) break;
            s.erase(it);
            cnt -= p.s - p.f;
            if (p.s > r) {
                s.insert({r, p.s});
                cnt += p.s - r;
            }
        }
        auto it = s.lower_bound({l, -1});
        if (it != s.begin()) {
            it--;
            pii p = *it;
            if (p.s > l) {
                s.erase(it);
                cnt -= p.s - p.f;
                s.insert({p.f, l});
                cnt += l - p.f;
            }
            if (p.s > r) {
                s.insert({r, p.s});
                cnt += p.s - r;
            }
        }
        if (k == 2) s.insert({l, r}), cnt += r - l;
        printf("%d\n", cnt);
    }
}