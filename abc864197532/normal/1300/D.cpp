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
    int x[n+1], y[n+1];
    fop (i,0,n) {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0];
    y[n] = y[0];
    int dx[n], dy[n];
    fop (i,0,n) {
        dx[i] = x[i+1] - x[i];
        dy[i] = y[i+1] - y[i];
    }
    if (n % 2) {
        cout << "NO" << endl;
        return 0;
    }
    fop (i,0,n/2) {
        if (dx[i] != -dx[i + n/2] or dy[i] != -dy[i + n/2]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}