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
const int LIM=4e5+7;
const ll MOD=1e9+7;
int F[LIM], ans;
int fnd(int x) {
        if(F[x]==x) return x;
        return F[x]=fnd(F[x]);
}
void uni(int a, int b) {
        if(fnd(a)==fnd(b)) return;
        --ans;
        F[fnd(b)]=fnd(a);
}
ll pot(ll a, ll b) {
        ll w=1;
        while(b) {
                if(b&1) w=(w*a)%MOD;
                b/=2;
                a=(a*a)%MOD;
        }
        return w;
}
void solve() {
        int n;
        cin >> n;
        ans=n;
        rep(i, n) F[i]=i;
        int wa[n], wb[n], a[n], b[n];
        vector<int>V[n];
        rep(i, n) {
                cin >> a[i]; --a[i];
                wa[a[i]]=i;
        }
        rep(i, n) {
                cin >> b[i]; --b[i];
                wb[b[i]]=i;
        }
        rep(i, n) {
                uni(i, wa[b[i]]);
                uni(i, wb[a[i]]);
        }
        cout << pot(2, ans) << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}