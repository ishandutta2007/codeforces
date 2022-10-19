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
        int a, b, c;
        cin >> a >> b >> c;
        int r=max(a, b)-min(a, b);
        if(max(max(a, b), c)>2*r) {
                cout << -1 << '\n';
                return;
        }
        if(c-r<=0) {
                cout << c+r << '\n';
        } else cout << c-r << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}