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
    int a[n], aa = 0;
    vector <pii> v;
    set <pii> s;
    fop (i,0,n) {
        cin >> a[i];
        if (i != a[i]) {
            s.insert({i, a[i]});
            v.pb({i, a[i]});
        } else {
            aa++;
        }
    }
    int c = 1;
    for (pii A : v) {
        if (s.count({A.Y, A.X})) {
            c = max(c, 2);
        }
    }
    cout << min(n, aa + c) << endl;
}