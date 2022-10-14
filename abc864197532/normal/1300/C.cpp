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

int main () {
    int n;
    cin >> n;
    int a[n];
    fop (i,0,n) cin >> a[i];
    int dp[30];
    bool is[30];
    fop (i,0,30) dp[i] = -1, is[i] = false;
    fop (i,0,n) {
        fop (j,0,30) {
            if (a[i] & (1 << j)) {
                if (dp[j] == -1) {
                    dp[j] = i;
                } else {
                    is[j] = true;
                }
            } 
        }
    }
    int p = 0;
    FOP (i,30,0) {
        if (!is[i] and dp[i] != -1) {
            p = dp[i];
            break;
        }
    }
    cout << a[p] << ' ';
    fop (i,0,n) {
        if (i == p) continue;
        cout << a[i] << ' ';
    }
    cout << endl;
}