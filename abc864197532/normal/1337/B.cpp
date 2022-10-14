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

void solve() {
    int x, a, b;
    cin >> x >> a >> b;
    while (a-- and x > 20) {
        x = x / 2 + 10;
    }
    if (x > b * 10) cout << "No\n";
    else cout << "Yes\n";
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}