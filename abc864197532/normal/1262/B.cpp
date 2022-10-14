#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define MAXN 200000

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p[n], ans[n], now = 0;
        set <int> s1;
        bool is = true;
        fop (i,1,n+1) s1.insert(i);
        fop (i,0,n) {
            cin >> p[i];
            if (now < p[i]) {
                ans[i] = p[i];
                now = p[i];
            } else {
                if (*s1.begin() > p[i]) {
                    is = false;
                } else {
                    ans[i] = *s1.begin();
                }
            }
            s1.erase(ans[i]);
        }
        if (!is) {
            cout << -1 << endl;
        } else {
            fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
        }
    }
}