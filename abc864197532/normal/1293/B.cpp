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
    int n;
    cin >> n;
    double ans = 0;
    fop (i,1,n+1) ans += double(1) / i;
    cout << fixed << setprecision(8) << ans << endl;
}