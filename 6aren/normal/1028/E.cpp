#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 150000;

int n, b[N], a[N];

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> b[i];

    int find = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] > b[(i + n - 1) % n]) {
            find = i;
            break;
        }
    } 

    if (find == -1) {
        if (b[0] == 0) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) cout << 1 << ' ';
        } else cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    a[find] = b[find];

    int cur = (find + n - 1) % n;

    do {
        int prev = b[(cur + n - 1) % n];
        int mod = a[(cur + 1) % n];
        int t = prev / mod + 1;
        a[cur] = t * mod + b[cur];
        cur = (cur + n - 1) % n;
    } while (cur != find);

    for (int i = 0; i < n; i++) cout << a[i] << ' ';

    return 0;
}