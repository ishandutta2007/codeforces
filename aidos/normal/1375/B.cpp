#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 9;
const int inf = (1<<30) - 1;
int n, m;
int a[333][333];
int b[333][333];

int dx[]= {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
void solve() {
    cin >> n >> m;
    for(int i = 0; i  < n; i++) {
        for(int j = 0; j < m; j++) {
            cin  >> a[i][j];
            b[i][j] = 0;
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 && x < n && y >= 0 && y < m) {
                    b[i][j]++;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {
            if(b[i][j] < a[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}