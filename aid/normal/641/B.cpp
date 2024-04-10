#include <iostream>

using namespace std;

const int MAXN = 105, MAXQ = 10 * 1000 + 5;
int a[MAXN][MAXN];
pair<pair<int, int>, pair<int, int> > p[MAXQ];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < q; i++) {
        cin >> p[i].first.first;
        if(p[i].first.first == 3)
            cin >> p[i].first.second >> p[i].second.first >> p[i].second.second;
        else
            cin >> p[i].first.second;
    }
    for(int i = q - 1; i >= 0; i--)
        if(p[i].first.first == 1) {
            int r = p[i].first.second - 1, aa = a[r][m - 1];
            for(int j = m - 1; j > 0; j--)
                a[r][j] = a[r][j - 1];
            a[r][0] = aa;
        }
        else if(p[i].first.first == 2) {
            int c = p[i].first.second - 1, aa = a[n - 1][c];
            for(int j = n - 1; j > 0; j--)
                a[j][c] = a[j - 1][c];
            a[0][c] = aa;
        }
        else {
            int r = p[i].first.second - 1, c = p[i].second.first - 1,
                x = p[i].second.second;
            a[r][c] = x;
        }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}