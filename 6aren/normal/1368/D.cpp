#include<bits/stdc++.h>
using namespace std;

#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

int a[25];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u; cin >> u;
        for (int j = 0; j < 20; j++) if (bit(u, j)) a[j]++;
    }

    long long ans = 0;
    while (1) {
        int tmp = 0;
        for (int i = 19; i >= 0; i--) {
            if (a[i]) tmp += (1 << i), a[i]--;
        }
        if (tmp == 0) break;
        ans = ans + 1LL * tmp * tmp;
    }
    cout << ans;
}