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

const int MN = 5005;

double p[MN];
int t[MN];
double prob[MN][MN];
int n, T;

int main() {
    boost();
    
    cin >> n >> T;
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> t[i];
        p[i] *= 0.01;
    }
    prob[0][0] = 1;
    double ans = 0, cur = 0, tmp = 0;
    double q;
    for (int i = 1; i <= n; ++i) {
        cur = 0, tmp = 0;
        q = pow(1 - p[i - 1], t[i - 1] - 1);
        for (int k = 0; k <= T; ++k) {
            cur = cur * (1 - p[i - 1]) + prob[i - 1][k];
            if (k >= t[i - 1] - 1) {
                cur -= prob[i - 1][k - t[i - 1] + 1] * q;
                prob[i][k] += prob[i - 1][k - t[i - 1]] * q;
            }
            if (k >= T - t[i - 1] && k < T) {
                tmp = prob[i - 1][k + 1] + (1 - p[i - 1]) * tmp;
            }
            prob[i][k + 1] = cur * p[i - 1];
        }
        ans += tmp * (i - 1);
    }
    for (int k = 0; k <= T; ++k) {
        ans += n * prob[n][k];
    }
    printf("%.12lf\n", ans);
    return 0;
}