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
        string x;
        cin >> n >> m >> x;
        vector<int>V;
        rep(i, n) if(x[i]=='1') {
                V.pb(i);
        }
        if(!V.size()) {
                cout << x << '\n';
                return;
        }
        for(int i=V[0]-1; i>=0 && V[0]-i<=m; --i) x[i]='1';
        for(int i=V.back()+1; i<n && i-V.back()<=m; ++i) x[i]='1';
        rep(i, V.size()-1) {
                int odl=V[i+1]-V[i]-1;
                rep(j, min(odl/2, m)) {
                        x[V[i]+j+1]='1';
                        x[V[i+1]-j-1]='1';
                }
        }
        cout << x << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}