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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, tmp, ans = 0;
        cin >> n >> x;
        bool is[300];
        fop (i,0,300) is[i] = false;
        fop (i,0,n) cin >> tmp, is[tmp] = true;
        fop (i,1,300) {
            if (!is[i]) {
                x--;
                if (x < 0) break;
            }
            ans++;
        }
        cout << ans << '\n';
    }
}