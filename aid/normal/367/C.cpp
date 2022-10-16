#include <iostream>
#include <algorithm>

using namespace std;

const int MAXM = 100 * 1000 + 5;
int w[MAXM];

bool good(int m, int n) {
    if(m % 2)
        return ((long long)m * (m - 1)) / 2 + 1 <= n;
    else
        return ((long long)m * (m - 1)) / 2 + m / 2 <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int q;
        cin >> q >> w[i];
    }
    int l = 1, r = n + 1;
    while(l < r - 1) {
        int mid = (l + r) / 2;
        if(good(mid, n))
            l = mid;
        else
            r = mid;
    }
    sort(w, w + m);
    long long ans = 0;
    for(int i = 0; i < l && m - i - 1 >= 0; i++)
        ans += w[m - i - 1];
    cout << ans << '\n';
    return 0;
}