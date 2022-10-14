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
    int n;
    cin >> n;
    int a[n], b[n];
    lli all = 0;
    fop (i,0,n) cin >> a[i], all += a[i];
    fop (i,0,n) cin >> b[i];
    sort(b, b + n);
    reverse(b, b + n);
    if (all > (b[0] + b[1])) cout << "NO\n";
    else cout << "YES\n";
}