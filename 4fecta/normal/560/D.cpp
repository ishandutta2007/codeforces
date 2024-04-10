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

unordered_map<string, bool> dp;

bool eq(string a, string b) {
    if (dp.count(a + " " + b)) return dp[a + " " + b];
    if (dp.count(b + " " + a)) return dp[b + " " + a];
    if (a == b) return true;
    if (a.size() % 2) return false;
    string a1 = a.substr(0, a.size() / 2);
    string a2 = a.substr(a.size() / 2, a.size() / 2);
    string b1 = b.substr(0, b.size() / 2);
    string b2 = b.substr(b.size() / 2, b.size() / 2);
    return dp[a + " " + b] = dp[b + " " + a] = (eq(a1, b1) && eq(a2, b2)) || (eq(a1, b2) && eq(a2, b1));
}

int main() {
    boost();

    string a, b;
    cin >> a >> b;
    printf("%s\n", eq(a, b) ? "YES\n" : "NO\n");

    return 0;
}