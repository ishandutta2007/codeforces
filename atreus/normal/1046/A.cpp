#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> order_set;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;

map <int, order_set> mp;

class robot {
    public:
        int x;
        int r;
        int iq;
        bool operator < (const robot &other) {
            return r > other.r;
        }
};

bool compare (robot fi, robot se) {
    return fi < se;
}

robot ro[maxn];

unordered_map <int, bool> mark;

int x[maxn];

int diff_creator = 0;
int main() {
    ios_base::sync_with_stdio (false);
    int n, k;
    scanf ("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d%d", &ro[i].x, &ro[i].r, &ro[i].iq);
        mark[ro[i].iq] = 1;
        x[i - 1] = ro[i].x;
    }

    sort (ro + 1, ro + n + 1, compare);
    sort (x, x + n);

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = lower_bound (x, x + n, ro[i].x - ro[i].r) - x + 1;
        int r = upper_bound (x, x + n, ro[i].x + ro[i].r) - x + 1;
//        cout << l << " " << r << endl;
        for (int j = ro[i].iq; j <= ro[i].iq + k; j++) {
            if (mark[j]) {
                int xp = mp[j].order_of_key({r, -1});
                int yp = mp[j].order_of_key({l, -1});
                ans += xp - yp;
            }
        }

        for (int j = ro[i].iq - 1; j >= max (0, ro[i].iq - k); j--) {
            if (mark[j]) {
                int xp = mp[j].order_of_key({r, -1});
                int yp = mp[j].order_of_key({l, -1});
                ans += xp - yp;
            }
        }

        int idx = lower_bound (x, x + n, ro[i].x) - x + 1;
        
        mp[ro[i].iq].insert ({idx, diff_creator ++});
    }
    printf ("%lld \n", ans);
}