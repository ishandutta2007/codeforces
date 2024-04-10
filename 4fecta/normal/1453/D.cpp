#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 2005;

int t, k, ans[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> k;
        vector<int> v;
        int sz = 0;
        if (k % 2) {printf("-1\n"); continue;}
        while (k) {
            for (int pw = 60; pw > 0; pw--) {
                int val = ((1LL << pw) - 1) * 2;
                if (val <= k) k -= val, sz += pw, v.push_back(pw);
            }
        }
        if (sz > 2000) {printf("-1\n"); continue;}
        printf("%d\n", sz);
        for (int p : v) {
            printf("1 ");
            for (int i = 1; i < p; i++) printf("0 ");
        }
        printf("\n");
    }

    return 0;
 }