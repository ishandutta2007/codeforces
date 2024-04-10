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
        int n, m;
        cin >> n >> m;
        ll T[n][m], ans=0;
        rep(i, n) rep(j, m) cin >> T[i][j];
        rep(i, (n+1)/2) rep(j, (m+1)/2) {
                vector<ll>V;
                V.pb(T[i][j]);
                V.pb(T[i][m-j-1]);
                V.pb(T[n-i-1][j]);
                V.pb(T[n-i-1][m-j-1]);
                sort(all(V));
                ans+=abs(V[1]-T[i][j]);
                T[i][j]=V[1];
                ans+=abs(V[1]-T[i][m-j-1]);
                T[i][m-j-1]=V[1];
                ans+=abs(V[1]-T[n-i-1][j]);
                T[n-i-1][j]=V[1];
                ans+=abs(V[1]-T[n-i-1][m-j-1]);
                T[n-i-1][m-j-1]=V[1];
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}