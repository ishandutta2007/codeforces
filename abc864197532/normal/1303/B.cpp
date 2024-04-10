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
        lli n,g,b,ans = 0;
        cin >> n >> g >> b;
        int na = (n + 1) / 2;
        if (g >= na) cout << n << endl;
        else {
            int k = na % g;
            ans += (na / g * (g + b));
            if (k > 0) ans += k;
            else ans -= b;
            cout << max(ans, n) << endl;
        }
    }
}