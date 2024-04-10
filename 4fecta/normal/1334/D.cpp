#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n, l, r, L[MN], R[MN];

vector<int> gen_seq(int m) {
    int sft = m + 1;
    vector<int> ret;
    for (int i = 1; i <= R[m] - L[m] + 1; i++) {
        if (i % 2) {ret.push_back(m); continue;}
        ret.push_back(sft);
        sft++;
    }
    return ret;
}

int32_t main() {
    boost();


    int t;
    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        int sta = 1, len = (n - 1) * 2;
        for (int i = 1; i < n; i++) {
            L[i] = sta; R[i] = sta + len - 1;
            sta = R[i] + 1;
            len -= 2;
            //printf("%d %d\n", L[i], R[i]);
        }
        for (int i = 1; i < n; i++) {
            //if (l > R[i] || r < L[i]) continue;
            int cnt = 0;
            if (l >= L[i] && r <= R[i]) {
               // printf("3f\n");
                cnt++;
                vector<int> v = gen_seq(i);
                int st = l - L[i];
                int ed = r - L[i];
                for (int i = st; i <= ed; i++) printf("%lld ", v[i]), len++;
                break;
            }
            if (l <= L[i] && r >= R[i]) {
                //printf("0f\n");
                cnt++;
                vector<int> v = gen_seq(i);
                for (int p : v) printf("%lld ", p), len++;
                //continue;
            }
            if (R[i] >= l && R[i] <= r && L[i] < l) {
                //printf("1f\n");
                cnt++;
                vector<int> v = gen_seq(i);
                int st = l - L[i];
                assert(st >= 0);
                for (int i = st; i < v.size(); i++) printf("%lld ", v[i]), len++;
                //continue;
            }
            if (L[i] <= r && L[i] >= l && R[i] > r) {
                //printf("2f\n");
                cnt++;
                vector<int> v = gen_seq(i);
                int ed = r - L[i];
                assert(ed < v.size());
                for (int i = 0; i <= ed; i++) printf("%lld ", v[i]), len++;
                //continue;
            }
        }
        if (r == n * (n - 1) + 1) printf("1 ");
        printf("\n");
    }

    return 0;
}