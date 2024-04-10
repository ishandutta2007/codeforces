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
        int n, k;
        string x;
        cin >> n >> k >> x;
        vector<int>pos;
        rep(i, n) if(x[i]=='*') {
                pos.pb(i);
        }
        int lst=pos[0], ans=min(int(pos.size()), 2);
        for(int i=1; i<pos.size(); ++i) {
                if(pos[i]-lst>k) {
                        ++ans;
                        lst=pos[i-1];
                }
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}