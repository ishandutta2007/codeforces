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
#define pli pair<lli,int> 
#define X first
#define Y second

vector <lli> f (long long n) {
    vector <lli> ans;
    for (int i = 2; 1ll * i * i <= n; ++i) {
        if (n % i) continue;
        ans.pb(i);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans.pb(n);
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <lli> input(n);
    fop (i,0,n) cin >> input[i];
    fop (i,1,n) input[i] += input[i-1];
    vector <lli> check = f(input[n - 1]);
    lli ans = 1ll << 60;
    for (lli p : check) {
        lli tmp = 0;
        fop (i,0,n) {
            tmp += min(input[i] % p, p - (input[i] % p));
        }
        ans = min(ans, tmp);
    }
    if (ans == 1ll << 60) ans = -1;
    cout << ans << endl;
}