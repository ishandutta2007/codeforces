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
    int n, a, b;
    cin >> n >> a >> b;
    lli v[n];
    fop (i,0,n) cin >> v[i];
    sort(v, v + n);
    reverse(v, v + n);
    if (a > b) swap(a, b);
    double ans = 0;
    lli aa = 0, bb = 0;
    fop (i,0,a) {
        aa += v[i];
    }
    fop (i,a,a+b) {
        bb += v[i];
    }
    ans += (1.0 * aa / a);
    ans += (1.0 * bb / b);
    cout << fixed << setprecision(10) << ans << endl;
}