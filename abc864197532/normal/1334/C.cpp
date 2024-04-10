#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli>
#define X first
#define Y second

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <pii> input(n);
        lli all = 0;
        fop (i,0,n) cin >> input[i].X >> input[i].Y, all += input[i].X;
        lli pre[n];
        fop (i,0,n) {
            int nxt = (i + 1) % n;
            pre[i] = min(input[i].Y, input[nxt].X);
        }
        sort(pre, pre + n);
        fop (i,1,n) all -= pre[i];
        cout << all << endl;
    }
}