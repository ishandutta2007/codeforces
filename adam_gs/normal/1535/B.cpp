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
        int ile[2]; ile[0]=ile[1]=0;
        vector<int>np;
        rep(i, n) {
                int a;
                cin >> a;
                ++ile[a%2];
                if(a%2==1) np.pb(a);
        }
        int ans=ile[0]*ile[1]+ile[0]*(ile[0]-1)/2;
        rep(i, np.size()) for(int j=i+1; j<np.size(); ++j) {
                if(__gcd(np[i], np[j])>1) ++ans;
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}