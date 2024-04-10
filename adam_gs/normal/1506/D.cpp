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
        int T[n], ma=0;
        map<int,int>mp;
        rep(i, n) {
                cin >> T[i];
                ++mp[T[i]];
                ma=max(ma, mp[T[i]]);
        }
        cout << max(n%2, 2*ma-n) << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}