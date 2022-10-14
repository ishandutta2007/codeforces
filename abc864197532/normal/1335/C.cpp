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
const int mod = 998244353;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, tmp;
        cin >> n;
        int aa[n];
        fop (i,0,n) aa[i] = 0;
        fop (i,0,n) {
            cin >> tmp;
            aa[tmp - 1]++;
        }
        sort(aa, aa + n);
        reverse(aa, aa + n);
        int now = 0;
        while (now < n and aa[now] > 0) now++;
        cout << max(min(aa[0] - 1, now), min(aa[0], now - 1)) << endl;;
    }
}