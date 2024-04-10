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
#define endl '\n'
int st[500][10][500][10];

bool ask(int x1, int y1, int x2, int y2, int k) {
    int nx1 = x1 + k - 1, ny1 = y1 + k - 1, nx2 = x2 - k, ny2 = y2 - k;
    if (nx1 >= nx2 or ny1 >= ny2) return false;
    int k1 = log2(nx2- nx1), k2 = log2(ny2 - ny1);
    int aa = max({st[nx1][k1][ny1][k2], st[nx2 - (1 << k1)][k1][ny1][k2], st[nx1][k1][ny2 - (1 << k2)][k2], st[nx2 - (1 << k1)][k1][ny2 - (1 << k2)][k2]});
    return aa >= k;
}


int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n, m ,q;
    cin >> n >> m >> q;
    string input[n];
    fop (i,0,n) cin >> input[i];
    int change[n][m-1];
    fop (i,0,n) fop (j,0,m-1) change[i][j] = 0;
    fop (i,0,n) {
        fop (j,0,m-1) {
            if (input[i][j] == 'R' and input[i][j+1] == 'G') {
                change[i][j] = 1;
                int now1 = j - 1, now2 = j + 2;
                while (now1 >= 0 and now2 < m and input[i][now1] == 'R' and input[i][now2] == 'G') {
                    now1--;
                    now2++;
                    change[i][j]++;
                }
            }
            if (input[i][j] == 'Y' and input[i][j+1] == 'B') {
                change[i][j] = -1;
                int now1 = j - 1, now2 = j + 2;
                while (now1 >= 0 and now2 < m and input[i][now1] == 'Y' and input[i][now2] == 'B') {
                    now1--;
                    now2++;
                    change[i][j]--;
                }
            }
        }
    }
    int result[n-1][m-1];
    fop (i,0,n-1) {
        fop (j,0,m-1) {
            result[i][j] = 0;
            if (change[i][j] > 0 and change[i+1][j] < 0) {
                int c = 1, aa = min(change[i][j], -change[i+1][j]);
                int now1 = i - 1, now2 = i + 2;
                result[i][j] = 1;
                while (now1 >= 0 and now2 < n and change[now1][j] > 0 and change[now2][j] < 0) {
                    aa = min({aa, change[now1][j], -change[now2][j]});
                    now1--;
                    now2++;
                    c++;
                	result[i][j] = max(result[i][j], min(c, aa));
                }
            }
        }
    }
    fop (i,0,n-1) fop (j,0,m-1) fop (k1,0,10) fop (k2,0,10) st[i][k1][j][k2] = 0;
    fop (i,0,n-1) {
        fop (j,0,m-1) {
            st[i][0][j][0] = result[i][j];
        }
        fop (j,1,10) {
            fop (k,0,m-1) {
                if (k + (1 << j - 1) >= m - 1) break;
                st[i][0][k][j] = max(st[i][0][k][j-1], st[i][0][k + (1 << j - 1)][j - 1]);
            }
        }
    }
    fop (k1,1,10) {
        fop (i,0,n-1) {
            fop (k2,0,10) {
                fop (j,0,m-1) {
                    if (i + (1 << k1 - 1) >= n - 1) continue;
                    st[i][k1][j][k2] = max(st[i][k1-1][j][k2], st[i + (1 << k1 - 1)][k1-1][j][k2]);
                }
            }
        }
    }
    int x1, y1, x2, y2;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        int ans = 0;
        FOP (i,10,0) {
            if (ask(x1,y1,x2,y2,ans+(1 << i))) ans += 1 << i;
        }
        cout << ans * 4 * ans << endl;
    }
}