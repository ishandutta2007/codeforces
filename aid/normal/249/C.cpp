#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5, MAXA = 105;
int a[MAXN];
long double pr[MAXN][MAXA];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pr[i][a[i]] = 1;
    }
    int q;
    cin >> q;
    long double ans = 0;
    for(int i = 0; i < n; i++)
        if(a[i] == 0)
            ans++;
    for(int i = 0; i < q; i++) {
        int v, u, k;
        cin >> v >> u >> k;
        v--;
        u--;
        ans -= pr[v][0];
        for(int j = 0; j < MAXA && j <= a[v]; j++) {
            long double p = pr[v][j];
            pr[v][j] = 0;
            int st = max(0, k + j - a[v]);
            long double x = 1;
            if(st > 0) {
                for(int l = 1; l <= st; l++)
                    x *= (long double)(j - st + l) / l;
                for(int l = 1; l <= k - st; l++)
                    x *= (long double)(a[v] - j - k + st + l) / l;
                for(int l = 1; l <= k; l++)
                    x *= (long double)l / (a[v] - k + l);
            }
            else {
                for(int l = 1; l <= k; l++)
                    x *= (long double)(a[v] - j - k + l) / (a[v] - k + l);
            }
            for(int l = st; l <= k && l <= j; l++) {
                pr[v][j - l] += p * x;
                x *= (long double)((j - l) * (k - l)) /
                    ((l + 1) * (a[v] - j - k + l + 1));
            }
        }
        a[v] -= k;
        a[u] += k;
        ans += pr[v][0];
        cout << ans << '\n';
    }
    return 0;
}