#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
const int N = 2020;

int main () {
    int n, k;
    cin >> n >> k;
    int row[n][n], col[n][n];
    char c;
    vector <int> min_row(n, 1 << 20), min_col(n, 1 << 20), max_row(n, -1), max_col(n, -1);
    fop (i,0,n) {
        fop (j,0,n) {
            row[i][j] = col[i][j] = 0;
            cin >> c;
            if (c == 'B') {
                min_row[i] = min(min_row[i], j);
                min_col[j] = min(min_col[j], i);
                max_row[i] = max(max_row[i], j);
                max_col[j] = max(max_col[j], i);
            }
        }
    }
    int ans = 0;
    fop (i,0,n) if (max_row[i] == -1) ans++;
    fop (i,0,n) if (max_col[i] == -1) ans++;
    fop (i,0,n) {
        fop (j,0,n) {
            if (j <= min_row[i] and max_row[i] <= j + k - 1 and max_row[i] != -1) {
                row[i][j] = 1;
            }
            if (i <= min_col[j] and max_col[j] <= i + k - 1 and max_col[j] != -1) {
                col[i][j] = 1;
            }
        }
    }
    /*
    fop (i,0,n) {
        fop (j,0,n) {
            cout << row[i][j];
        }
        cout << endl;
    }
    fop (i,0,n) {
        fop (j,0,n) {
            cout << col[i][j];
        }
        cout << endl;
    }
    */
    int nrow[n][n], ncol[n][n];
    fop (i,0,n-k+1) {
        fop (j,0,n-k+1) {
            ncol[i][j] = 0;
            if (j) {
                ncol[i][j] = ncol[i][j-1] + col[i][j+k-1] - col[i][j-1];
            } else {
                fop (_,0,k) ncol[i][j] += col[i][_];
            }
        }
    }
    fop (i,0,n-k+1) {
        fop (j,0,n-k+1) {
            nrow[i][j] = 0;
            if (i) {
                nrow[i][j] = nrow[i-1][j] + row[i+k-1][j] - row[i-1][j];
            } else {
                fop (_,0,k) nrow[i][j] += row[_][j];
            }
        }
    }
    int tmp = 0;
    fop (i,0,n-k+1) {
        fop (j,0,n-k+1) {
            tmp = max(tmp, nrow[i][j] + ncol[i][j]);
        }
    }
    cout << ans + tmp << endl;
}