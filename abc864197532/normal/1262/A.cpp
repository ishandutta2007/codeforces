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
        int n, a, b, ll, rr;
        cin >> n;
        cin >> ll >> rr;
        fop (i,0,n-1) {
            cin >> a >> b;
            ll = max(ll, a);
            rr = min(rr, b);
        }
        cout << max(ll - rr, 0) << endl;
    }
}