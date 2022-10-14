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

void solve () {
    int n;
    cin >> n;
    fop (i,2,30) {
        if (n % ((1 << i) - 1) == 0) {
            cout << n / ((1 << i) - 1) << endl;
            return;
        }
    }
}

int main () {
    int t;
    cin >> t;
    while (t--) solve();
}