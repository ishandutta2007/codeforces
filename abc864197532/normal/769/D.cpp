#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli>
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, tmp;
    cin >> n >> k;
    int cnt[10001];
    fop (i,0,10001) cnt[i] = 0;
    fop (i,0,n) cin >> tmp, cnt[tmp]++;
    lli ans = 0;
    fop (i,0,10001) {
        fop (j,i,10001) {
            if (__builtin_popcount(i ^ j) == k) {
                if (i != j) ans += 1ll * cnt[i] * cnt[j];
                else ans += 1ll * (cnt[i] - 1) * cnt[i] / 2;
            }
        }
    }
    cout << ans << endl;
}