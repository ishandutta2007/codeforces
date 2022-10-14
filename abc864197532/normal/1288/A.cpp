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
    int t;
    cin >> t;
    while (t--) {
        lli a,b;
        cin >> a >> b;
        int n = sqrt(b);
        bool is = false;
        fop (i,n-2,n+3) {
            if (i <= 0) continue;
            if (i - 1 + (b + i - 1) / i <= a or b <= a) {
                is = true;
                break;
            }
        }
        if (is) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}