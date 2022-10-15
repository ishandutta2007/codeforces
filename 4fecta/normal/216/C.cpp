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

const int MN = 1005;

int n, m, k;
vector<int> ans;

int main() {
    boost();

    cin >> n >> m >> k;
    int len = n + m + 1;
    int til = n;
    int ex = 1;
    for (int i = 0; i < k; i++) ans.push_back(1);
    while (til < len) {
        if (ex) {
            ex = 0;
            ans.push_back(til);
            til++;
        } else {
            ex = 1;
            for (int i = 0; i < k - 1; i++) ans.push_back(til);
            //if (n == 2) {ans.pop_back(); continue;}
            til += n - 1;
            if (k == 1) til--;
        }
    }
    printf("%lld\n", ans.size());
    for (int i : ans) printf("%d ", i);

    return 0;
}