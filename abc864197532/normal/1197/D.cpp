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
    int n, m, k;
    cin >> n >> m >> k;
    int in[n];
    fop (i,0,n) cin >> in[i];
    lli bb[n], ans = 0, now = 0;
    fop (i,0,m) {
        fop (j,0,n) {
            bb[j] = in[j];
            if (i == j % m) bb[j] -= k;
        }
        now = 0;
        fop (j,0,n) {
            now += bb[j];
            if (now < 0) now = 0;
            if (i == j % m) ans = max(ans, now);
        }
    }
    cout << ans << endl;
}