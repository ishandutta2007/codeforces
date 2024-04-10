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
        string a, b;
        cin >> a >> b;
        int ans=a.size()+b.size();
        rep(i, a.size()) for(int j=i; j<a.size(); ++j) {
                bool t=false;
                for(int l=0; l<int(b.size())-(j-i); ++l) {
                        if(a.substr(i, j-i+1)==b.substr(l, (j-i+1))) t=true;
                }
                if(t) ans=min(ans, int(a.size()+b.size()-2*(j-i+1)));
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}