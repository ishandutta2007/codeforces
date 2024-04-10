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

int oo, oi, io, ii, co, ci;
string ans;

void oof() {
    printf("Impossible\n");
    exit(0);
}

int rec(int num) {
    for (int i = 1; i <= 100000; i++) {
        if (i * (i - 1) / 2 == num) return i;
    }
    return -1;
}

int32_t main() {
    boost();

    cin >> oo >> oi >> io >> ii;
    co = rec(oo), ci = rec(ii);
    if (co < 0 || ci < 0) oof();
    int sum = oi + io, inv = co * ci;
    if (sum != inv) {
        if (sum == 0 && co == 1) co = 0, inv = 0;
        else if (sum == 0 && ci == 1) ci = 0, inv = 0;
        else oof();
    }
    for (int i = 0; i < co; i++) ans += "0";
    for (int i = 0; i < ci; i++) ans += "1";
    inv = io;
    //printf("%d\n", inv);
    for (int i = co; i < ans.size(); i++) {
        if (!inv) break;
        if (inv < co) swap(ans[i], ans[i - inv]), inv = 0;
        else swap(ans[i], ans[i - co]), inv -= co;
    }
    printf("%s\n", ans.c_str());

    return 0;
}