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

void solve() {
    int n, m, tmp;
    cin >> n >> m;
    int x[n];
    fop (i,0,n) cin >> x[i];
    set <int> could;
    fop (i,0,m) {
        cin >> tmp;
        tmp--;
        could.insert(tmp);
    }
    fop (i,0,n) {
        int j = i;
        if (could.count(i)) {
            while (could.count(j)) j++;
            sort(x + i, x + j + 1);
        }
    }
    fop (i,0,n-1) {
        if (x[i] > x[i+1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main () {
    int t, a, b, c;
    cin >> t;
    while (t--) {
        solve();
    }
}