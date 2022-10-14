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

int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, m, tmp, all = 0;
        cin >> n >> m;
        fop (i,0,n) cin >> tmp, all += tmp;
        cout << min(all, m) << endl;
    }
}