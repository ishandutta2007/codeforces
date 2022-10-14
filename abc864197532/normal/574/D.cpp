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
const int N = 1e6;

int main () {
    int n;
    cin >> n;
    vector <int> input(n + 2);
    input[0] = input[n + 1] = 0;
    fop (i,0,n) cin >> input[i + 1];
    int a[n + 2], b[n + 2];
    a[0] = 0; b[n + 1] = 0;
    fop (i,1,n+2) a[i] = min(a[i - 1] + 1, input[i]);
    FOP (i,n+1,0) b[i] = min(b[i + 1] + 1, input[i]);
    int ans = 0;
    fop (i,0,n+2) ans = max(ans, min(a[i], b[i]));
    cout << ans << endl;
}