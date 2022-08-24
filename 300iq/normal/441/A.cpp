#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

int main() {
    int n, v, k, s;
    scanf("%d%d", &n, &v);
    set <int> ans;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &s);
            if (v > s) {
                ans.insert(i + 1);
            }
        }
    }
    printf("%d\n", (int) ans.size());
    for (auto x : ans) {
        printf("%d ", x);
    }
    puts("");
}