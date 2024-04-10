#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int MAXN = 1e7 + 228;

int ans[MAXN];
int is_prime[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans[x]++;
    }
    for (int i = 2; i < MAXN; i++) {
        is_prime[i] = 1;
    }
    for (int i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < MAXN; j += i) {
                ans[i] += ans[j];
                is_prime[j] = 0;
            }
        } else {
            ans[i] = 0;
        }
    }
    for (int i = 1; i < MAXN; i++) {
        ans[i] += ans[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        l = min(l, MAXN - 1);
        r = min(r, MAXN - 1);
        cout << ans[r] - ans[l] << endl;
    }
}