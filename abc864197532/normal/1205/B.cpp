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
#define X first
#define Y second
#define MAXN 100000
#define nMAXN 400

int now[MAXN], ans = 1 << 20;
lli input[MAXN];
int path[nMAXN][nMAXN], path2[nMAXN][nMAXN];

int main () {
    int n, m, t = 0;
    cin >> n;
    fop (i,0,n) cin >> input[i];
    fop (i,0,n) now[i] = -1;
    vector <int> aa;
    map <int, int> newn;
    fop (i,0,nMAXN) {
        fop (j,0,nMAXN) {
            path[i][j] = 1 << 20;
            path2[i][j] = 1 << 20;
        }
    }
    fop (k,0,60) {
        fop (i,0,n) {
            if (input[i] & (1ll << k)) {
                aa.pb(i);
            }
        }
        if (aa.size() > 2) {
            cout << 3 << endl;
            return 0;
        } else if (aa.size() == 2) {
            if (!newn.count(aa[0])) newn[aa[0]] = t++;
            if (!newn.count(aa[1])) newn[aa[1]] = t++;
            path[newn[aa[0]]][newn[aa[1]]] = 1;
            path[newn[aa[1]]][newn[aa[0]]] = 1;
            path2[newn[aa[0]]][newn[aa[1]]] = 1;
            path2[newn[aa[1]]][newn[aa[0]]] = 1;
        }
        aa.clear();
    }
    
    fop (k,0,t) {
        fop (i,0,t) {
            fop (j,i+1,t) {
                ans = min(ans, path[i][j] + path2[i][k] + path2[k][j]);
            }
        }
        fop (i,0,t) {
            fop (j,0,t) {
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }
    
    if (ans == 1 << 20) ans = -1;
    cout << ans << endl;
}
/*
000011
000110
101100
001001

000101
001100
001001
010000
110000
*/