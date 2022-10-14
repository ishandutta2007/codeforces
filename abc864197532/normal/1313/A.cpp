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

int main () {
    int t;
    cin >> t;
    while (t--) {
        int x[3], ans = 0;
        cin >> x[0] >> x[1] >> x[2];
        sort(x, x + 3);
        reverse(x, x + 3);
        int a = x[0], b = x[1], c = x[2];
        if (a) {
            a--;
            ans++;
        }
        if (b) {
            b--;
            ans++;
        }
        if (c) {
            c--;
            ans++;
        }
        if (a and b) {
            a--;
            b--;
            ans++;
        }
        if (a and c) {
            a--;
            c--;
            ans++;
        }
        if (b and c) {
            b--;
            c--;
            ans++;
        }
        if (a and b and c) {
            ans++;
        }
        cout << ans << endl;
    }
}