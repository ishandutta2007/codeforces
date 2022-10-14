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
    int a[n];
    lli aa = 0;
    fop (i,0,n) {
        cin >> a[i];
        aa += a[i];
    }
    if (aa % n == 0) {
        aa /= n;
        vector <pii> ans;
        fop (i,0,n) {
            if (a[i] != aa) ans.eb(aa - a[i], i);
        }
        if (ans.size() == 2) {
            int t = ans[0].X, tt = ans[0].Y, ttt = ans[1].Y;
            tt++, ttt++;
            if (t < 0) swap(tt, ttt);
            cout << abs(t) << " ml. from cup #" << tt << " to cup #" << ttt << ".\n";
        } else if (ans.size() == 0) {
            cout << "Exemplary pages.\n";
        } else {
            cout << "Unrecoverable configuration.\n";
        }
    } else {
        cout << "Unrecoverable configuration.\n";
    }
}