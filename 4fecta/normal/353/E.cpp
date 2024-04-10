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

const int MN = 1000005;

int n, mark[MN];
string s;

int main(){
    boost();

    cin >> s, n = s.size();
    vector<int> gir;
    for (int i = 0; i < n; i++) if (s[i] != s[(i + 1) % n]) gir.push_back(i);
    if (gir.size() == n) return 0 * printf("%d\n", n / 2);
    int ans = 0;
    for (int i = 0; i < gir.size(); i++) if ((gir[i] + 1) % n != gir[(i + 1) % gir.size()]) ans++, mark[i] = mark[(i + 1) % gir.size()] = 1;
    for (int i = 0; i < gir.size(); i++) if (!mark[i]) ans++, mark[i] = mark[(i - 1 + gir.size()) % gir.size()] = mark[(i + 1) % gir.size()] = 1;
    printf("%d\n", ans);

    return 0;
}