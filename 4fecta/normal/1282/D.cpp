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

string g1, g2, s;
int acnt, bcnt;

int guess(string x) {
    printf("%s\n", x.c_str());
    fflush(stdout);
    int ret; cin >> ret;
    return ret;
}

int main() {
    boost();

    for (int i = 1; i <= 300; i++) g1 += 'a', g2 += 'b';
    acnt = 300 - guess(g1), bcnt = 300 - guess(g2);
    for (int i = 1; i <= acnt + bcnt; i++) s += 'a';
    int bench = (300 - acnt) - (300 - acnt - bcnt);
    for (int i = 0; i < s.size() - 1; i++) {
        s[i] = 'b';
        int tmp = guess(s);
        if (tmp > bench) s[i] = 'a';
        bench = min(bench, tmp);
    }
    if (bench) s[s.size() - 1] = 'b';
    guess(s);

    return 0;
}