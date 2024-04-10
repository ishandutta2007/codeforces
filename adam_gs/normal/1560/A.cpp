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
vector<int>ans;
void solve() {
        int k;
        cin >> k;
        cout << ans[k-1] << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        rep(i, 1000000) {
                if((i+1)%3!=0 && (i+1)%10!=3) ans.pb(i+1);
        }
        int _=1;
        cin >> _;
        while(_--) solve();
}