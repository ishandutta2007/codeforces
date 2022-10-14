#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, x, y, tmp;
        lli k;
        cin >> n;
        lli nn[n+1];
        nn[0] = 0;
        fop (i,1,n+1) cin >> nn[i];
        sort(nn+1,nn+n+1);
        reverse(nn+1,nn+n+1);
        fop (i,1,n+1) {
            nn[i] = nn[i] + nn[i-1];
        }
        cin >> a >> x >> b >> y >> k;
        int a1=0, a2=0, a3=0;
        bool is=false;
        fop (i,0,n) {
            lli ans=0;
            if ((i+1) % x == 0 && (i+1) % y == 0) {
                a3++;
            } else if ((i+1) % x == 0) {
                if (a > b) a2++;
                else a1++;
            } else if ((i+1) % y == 0) {
                if (a > b) a1++;
                else a2++;
            }
            ans += (a + b) * nn[a3] / 100;
            ans += max(a, b) * (nn[a3+a2] - nn[a3]) / 100;
            ans += min(a, b) * (nn[a3+a2+a1] - nn[a3+a2]) / 100;
            if (ans >= k) {
                cout << i+1 << endl;
                is=true;
                break;
            }
        }
        if (!is) cout << -1 << endl;
    }
}