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
        int n,tmp;
        cin >> n;
        pii a[n];
        fop (i,0,n) {
            cin >> tmp;
            int aa = 0;
            while (!(tmp & 1)) {
                tmp >>= 1;
                aa++;
            }
            a[i] = mp(tmp, aa);
        }
        sort(a, a+n);
        int ans = 0;
        fop (i,0,n-1) {
            if (a[i].first < a[i+1].first) {
                ans += a[i].second;
            }
        }
        ans += a[n-1].second;
        cout << ans << endl;
    }
}