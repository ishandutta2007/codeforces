#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 5005, INF = 100 * 1000 * 1000;
int t[MAXN], l[MAXN], r[MAXN], d[MAXN], a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        a[i] = INF;
    for(int i = 0; i < m; i++) {
        cin >> t[i] >> l[i] >> r[i] >> d[i];
        t[i]--;
        l[i]--;
        r[i]--;
    }
    for(int i = m - 1; i >= 0; i--)
        if(t[i])
            for(int j = l[i]; j <= r[i]; j++)
                a[j] = min(a[j], d[i]);
        else
            for(int j = l[i]; j <= r[i]; j++)
                a[j] -= d[i];
    for(int i = 0; i < n; i++)
        b[i] = a[i];
    for(int i = 0; i < m; i++)
        if(t[i]) {
            int res = -INF;
            for(int j = l[i]; j <= r[i]; j++)
                res = max(res, b[j]);
            if(res != d[i]) {
                cout << "NO\n";
                return 0;
            }
        }
        else
            for(int j = l[i]; j <= r[i]; j++)
                b[j] += d[i];
    cout << "YES\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}