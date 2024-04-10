#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(ll a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=107;
ll T[LIM], n, m, k;
bool spr(ll x) {
        int po=0, ko=n-1;
        while(po<ko) {
                int sr=(po+ko+1)/2;
                if(T[sr]>x) ko=sr-1; else po=sr;
        }
        if(T[po]>x) --po;
        return x-po-1>=k;
}
void solve() {
        cin >> n >> m;
        k=1ll<<m; k-=n; k=(k-1)/2;
        rep(i, n) {
                string x;
                cin >> x;
                reverse(all(x));
                T[i]=0;
                rep(j, m) if(x[j]=='1') T[i]+=1ll<<j;
        }
        sort(T, T+n);
        ll po=0, ko=1ll<<m; --ko;
        while(po<ko) {
                ll sr=(po+ko)/2;
                if(spr(sr)) ko=sr; else po=sr+1;
        }
        string ans="";
        rep(i, m) ans+=(po&(1ll<<i)?"1":"0");
        reverse(all(ans));
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _;
        cin >> _;
        while(_--) solve();
}