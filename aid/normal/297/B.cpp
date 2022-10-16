#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    reverse(a, a + n);
    sort(b, b + m);
    reverse(b, b + m);
    for(int i = 0; i < min(n, m); i++)
        if(a[i] > b[i]) {
            cout << "YES\n";
            return 0;
        }
    if(n > m) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}