#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
void solve() {
        int n;
        cin >> n;
        int T[n], mi=101;
        rep(i, n) {
                cin >> T[i];
                mi=min(mi, T[i]);
        }
        if(mi<0) {
                cout << "NO\n";
                return;
        }
        cout << "YES\n";
        cout << 101 << '\n';
        rep(i, 101) cout << i << " ";
        cout << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}