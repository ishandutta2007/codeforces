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
    int a[n];
    fop (i,0,n) cin >> a[i];
    int ans = INT_MAX;
    fop (i,1,n-1) {
        ans = min({ans, min(a[i], a[0]) / i, min(a[n-1], a[i]) / (n - i - 1)});
    }
    ans = min({ans, min(a[n-1], a[0]) / (n-1)});
    cout << ans << endl;

}