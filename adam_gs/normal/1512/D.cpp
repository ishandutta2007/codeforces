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
        map<ll,int>mp;
        ll T[n+2], sum=0;
        rep(i, n+2) {
                cin >> T[i];
                sum+=T[i];
                ++mp[T[i]];
        }
        rep(i, n+2) {
                if(mp[sum-2*T[i]] && (mp[sum-2*T[i]]>1 || sum-2*T[i]!=T[i])) {
                        rep(j, n+2) {
                                if(mp[T[j]]>1 || T[j]!=sum-2*T[i]) {
                                        --mp[T[j]];
                                        if(i!=j) cout << T[j] << " ";
                                }
                        }
                        cout << '\n';
                        return;
                }
        }
        cout << "-1\n";
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}