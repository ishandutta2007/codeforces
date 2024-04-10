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

int main () {
    int n,q,p=0;
    cin >> n >> q;
    int isJava[2][n];
    fop (i,0,n) isJava[0][i] = 0, isJava[1][i] = 0;
    while (q--) {
        int a,b;
        cin >> a >> b;
        a--, b--;
        if (isJava[a][b]) {
            isJava[a][b] = 1 - isJava[a][b];
            fop (i,b-1,b+2) {
                if (i < 0 or i >= n) continue;
                if (isJava[1-a][i]) p--;
            }
        } else {
            isJava[a][b] = 1 - isJava[a][b];
            fop (i,b-1,b+2) {
                if (i < 0 or i >= n) continue;
                if (isJava[1-a][i]) p++;
            }
        }
        if (p > 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}