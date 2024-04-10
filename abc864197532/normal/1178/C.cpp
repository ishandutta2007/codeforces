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
    int a,b,MOD=998244353;
    cin >> a >> b;
    lli ans = 1;
    fop (i,0,a+b) ans = (ans * 2) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}