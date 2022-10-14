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
    int n, d;
    cin >> n >> d;
    int t[n], all = 0;
    fop (i,0,n) cin >> t[i], all += t[i];
    all += 10 * (n - 1);
    if (all > d) {
        cout << -1 << endl;
    } else {
        cout << 2 * (n - 1) + (d - all) / 5 << endl;
    }
}