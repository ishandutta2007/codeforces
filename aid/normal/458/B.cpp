#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5;
const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;
int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    long long sa = 0, sb = 0;
    for(int i = 0; i < m; i++)
        sb += b[i];
    long long ans = INF;
    for(int i = 0; i < n; i++) {
        if((long double)sb * (n - i) < INF)
            ans = min(ans, sb * (n - i) + sa);
        sa += a[i];
    };
    sb = 0;
    for(int i = 0; i < m; i++) {
        if((long double)sa * (m - i) < INF)
            ans = min(ans, sa * (m - i) + sb);
        sb += b[i];
    }
    cout << ans << '\n';
    return 0;
}