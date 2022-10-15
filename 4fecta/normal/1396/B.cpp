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

const int MN = 105;

int n, a[MN];

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
        sort(a + 1, a + n + 1);
        int rem = sum - a[n];
        if (rem < a[n]) {
            printf("T\n");
            continue;
        }
        if (sum % 2 == 0) { //T try to make 1 pile
            while (1) {
                int cnt = 0;
                for (int i = 1; i <= n; i++) if (a[i]) cnt++;
                if (cnt == 1) {
                    printf("T\n");
                    break;
                }
                if (cnt == 0) {
                    printf("HL\n");
                    break;
                }

                for (int i = 1; i <= n; i++) {
                    if (a[i]) {
                        a[i]--;
                        break;
                    }
                }
                int pos = n;
                while (a[pos] == a[pos - 1] && pos > 1) pos--;
                a[pos]--;
            }
        } else {
            int pos = n;
            while (a[pos] == a[pos - 1] && pos > 1) pos--;
            a[pos]--;
            while (1) {
                int cnt = 0;
                for (int i = 1; i <= n; i++) if (a[i]) cnt++;
                if (cnt == 1) {
                    printf("HL\n");
                    break;
                }
                if (cnt == 0) {
                    printf("T\n");
                    break;
                }

                for (int i = 1; i <= n; i++) {
                    if (a[i]) {
                        a[i]--;
                        break;
                    }
                }
                int pos = n;
                while (a[pos] == a[pos - 1] && pos > 1) pos--;
                a[pos]--;
            }
        }
    }

    return 0;
}