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

int main() {
    int n;
    cin >> n;
    map <int, lli> m1; 
    int summ = 0;
    lli ans = 1ll * n * n;
    vector <int> minn, maxx;
    fop (i,0,n) {
        int t;
        cin >> t;
        int a[t];
        bool is = true;
        fop (j,0,t) {
            cin >> a[j];
        }
        fop (j,1,t) {
            if (a[j-1] < a[j]) {
                is = false;
                break;
            }
        }
        if (is) {
            maxx.pb(a[0]);
            minn.pb(a[t-1]);
        }
    }
    sort(minn.begin(), minn.end());
    for (int i : maxx) ans -= (minn.size() - (lower_bound(minn.begin(), minn.end(), i) - minn.begin()));
    cout << ans << endl;
}