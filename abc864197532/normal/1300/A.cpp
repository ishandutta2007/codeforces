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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], ans = 0, all = 0;
        fop (i,0,n) {
            cin >> a[i];
            if (a[i] == 0) {
                a[i] = 1;
                ans++;
            }
            all += a[i];
        }
        if (all == 0) ans++;
        cout << ans << endl;
    }
}