#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int a[305][305], b[305][305];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

bool in(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cin >> a[i][j];
        }

        bool ok = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                b[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    if (in(i + dx[k], j + dy[k])) b[i][j]++;
                }

                if (a[i][j] > b[i][j]) ok = 0; 
            }
        }

        if (ok == 0) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) cout << b[i][j] << ' ';
                cout << '\n';
            }
        }

    }
    return 0;
}