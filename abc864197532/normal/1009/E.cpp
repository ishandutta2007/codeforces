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
#define endl '\n'
const int mod = 998244353;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> input(n);
    fop (i,0,n) cin >> input[i];
    lli ans = 0, now = 1;
    fop (i,0,n) {
        lli tmp;
        if (i) {
            tmp = 1ll * input[n - i - 1] * (i + 2) % mod * now % mod;
            now = now * 2 % mod;
        } else tmp = input[n - i - 1] % mod;
        ans = (ans + tmp) % mod;
    }
    cout << ans << endl;
}