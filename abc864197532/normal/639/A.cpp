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
    int n, k, q, a, b;
    cin >> n >> k >> q;
    int v[n];
    fop (i,0,n) cin >> v[i];
    set <pii, greater<pii>> s;
    while (q--) {
        cin >> a >> b; b--;
        if (a == 1) {
            s.insert({v[b], b});
        } else {
            set <pii> aaa;
            while (s.size() and aaa.size() < k) {
                aaa.insert(*s.begin());
                s.erase(s.begin());
            }
            if (aaa.count(mp(v[b], b))) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            while (aaa.size()) {
                s.insert(*aaa.begin());
                aaa.erase(aaa.begin());
            }
        }
    }
}