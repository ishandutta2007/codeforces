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
const int INF=1e9+7;
void solve() {
        ll ans=0, n, szuk=INF, akt=0, p;
        cin >> n;
        ll T[n];
        rep(i, n) {
                cin >> T[i];
                if(T[i]<=0) ++ans;
                else szuk=min(szuk, T[i]);
        }
        sort(T, T+n);
        p=szuk;
        for(int i=n-1; i>=0; --i) {
                if(T[i]<=szuk) {
                        szuk=T[i]-p;
                        ++akt;
                }
        }
        cout << max(ans, akt) << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _;
        cin >> _;
        while(_--) solve();
}