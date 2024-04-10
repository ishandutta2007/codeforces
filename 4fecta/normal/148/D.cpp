#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 1005;

double x, y;
double dp[MN][MN];

double f(double w, double b) {
    if (w <= 0) return 0;
    if (b <= 0) return 1;
    if (dp[(int)w][(int)b] != -1) return dp[(int)w][(int)b];
    double ret = w / (w + b);
    double tmp = (1 - ret) * ((b - 1) / (w + b - 1));
    if (tmp < 1e-12) return dp[(int)w][(int)b] = ret;
    b -= 2;
    return dp[(int)w][(int)b + 2] = ret + tmp * (f(w, b - 1) * (b / (w + b)) + f(w - 1, b) * (w / (w + b)));
}

int main() {
    boost();

    cin >> x >> y;
    for (int i = 0; i < MN; i++) for (int j = 0; j < MN; j++) dp[i][j] = -1;
    printf("%.10f\n", f(x, y));

    return 0;
}