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

int randint(int a, int b) {
    int rnd = rand();
    return rnd % (a - b + 1) + a;
}

int read() {
    string s;
    cin >> s;
    fflush(stdout);
    if (s == "FIRST") return 1;
    if (s == "SECOND") return 2;
    if (s == "EQUAL") return 3;
    return -1;
}

int n, k;

int main() {
    srand(time(NULL));

    int t;
    cin >> t;
    while (t--) {
        bool fst = 0;
        cin >> n >> k;
        for (int i = 1; i <= 25; i++) {
            printf("? 1 1\n1\n%d\n", randint(2, n));
            int ans = read();
            if (ans == 2) fst = 1;
        }
        if (fst) {
            printf("! 1\n");
            continue;
        }
        int lft = 1, rit = 1;
        while (1) {
            int nl = rit + 1, nb = rit * 2;
            if (nb >= n) {
                lft = rit + 1;
                rit = n;
                break;
            }
            printf("? %d %d\n", rit - lft + 1, rit - lft + 1);
            for (int i = lft; i <= rit; i++) printf("%d ", i);
            printf("\n");
            for (int i = nl; i <= nb; i++) printf("%d ", i);
            printf("\n");
            int ans = read();
            if (ans == 1) {
                lft = nl, rit = nb;
                break;
            }
            rit = nb;
        }
        while (lft < rit) {
            int mid = (lft + rit) >> 1;
            printf("? %d %d\n", mid - lft + 1, mid - lft + 1);
            for (int i = 1; i <= mid - lft + 1; i++) printf("%d ", i);
            printf("\n");
            for (int i = lft; i <= mid; i++) printf("%d\n", i);
            printf("\n");
            int ans = read();
            if (ans == 1) rit = mid;
            else lft = mid + 1;
        }
        printf("! %d\n", lft);
    }

    return 0;
}