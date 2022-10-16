#include <iostream>

using namespace std;

const int MAXN = 505;
int x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(20);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    int num = 0, den = 1;
    for(int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;
        if((x[v] + x[u]) * den > num * w) {
            num = x[v] + x[u];
            den = w;
        }
    }
    cout << (long double)num / den << '\n';
    return 0;
}