#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define MAXN 200000

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector <int> a(n), l, r;
    fop (i,0,n) {
        if (s[i] == '(') a[i] = 0;
        else a[i] = 1;
    }
    fop (i,0,n) {
        if (a[i] != i % 2) {
            fop (j,i+1,n) {
                if (a[j] == i % 2) {
                    l.pb(i);
                    r.pb(j);
                    break;
                }
            }
            reverse(a.begin() + l.back(), a.begin() + r.back() + 1);
        }
    }
    if (n / 2 != k) {
        l.pb(1);
        r.pb(2 * (n / 2 - k));
    }
    cout << n << endl;
    fop (i,0,l.size()) {
        cout << l[i] + 1 << ' ' << r[i] + 1 << endl;
    }
    fop (i,l.size(),n) {
        cout << "1 1" << endl;
    }
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}