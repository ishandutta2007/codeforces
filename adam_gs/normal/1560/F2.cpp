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
const ll INF=1e10+7;
void solve() {
        ll n, k;
        cin >> n >> k;
        vector<ll>V;
        while(n) {
                V.pb(n%10);
                n/=10;
        }
        reverse(all(V));
        vector<int>bylo(10);
        ll ans=INF, c=0, xd=0;
        for(auto i : V) {
                if(!bylo[i]) ++c;
                bylo[i]=1;
                xd*=10;
                xd+=i;
        }
        if(c<=k) {
                cout << xd << '\n';
                return;
        }
        rep(i, 10) bylo[i]=0;
        rep(i, V.size()) {
                if(V[i]<9) {
                        if(k>=2 || (k>=1 && bylo[V[i]+1])) {
                                ll akt=0;
                                rep(j, i) {
                                        akt*=10;
                                        akt+=V[j];
                                }
                                akt*=10;
                                akt+=V[i]+1;
                                for(int j=i+1; j<V.size(); ++j) akt*=10;
                                ans=min(ans, akt);
                        } else if(k>=1) {
                                ll akt=0;
                                rep(j, i) {
                                        akt*=10;
                                        akt+=V[j];
                                }
                                akt*=10;
                                akt+=V[i]+1;
                                for(int j=i+1; j<V.size(); ++j) {
                                        for(int l=0; l<10; ++l) {
                                                if(bylo[l] || l==V[i]+1) {
                                                        akt*=10;
                                                        akt+=l;
                                                        break;
                                                }
                                        }
                                }
                                ans=min(ans, akt);
                        } else {
                                bool ok=true;
                                ll akt=0;
                                rep(j, i) {
                                        akt*=10;
                                        akt+=V[j];
                                }
                                akt*=10;
                                ll x=V[i];
                                for(int j=9; j>V[i]; --j) {
                                        if(bylo[j]) x=j;
                                }
                                if(x==V[i]) ok=false;
                                akt+=x;
                                for(int j=i+1; j<V.size(); ++j) {
                                        for(int l=0; l<10; ++l) {
                                                if(bylo[l]) {
                                                        akt*=10;
                                                        akt+=l;
                                                        break;
                                                }
                                        }
                                }
                                if(ok) ans=min(ans, akt);
                        }
                }
                if(!bylo[V[i]]) --k;
                bylo[V[i]]=1;
                if(k<0) break;
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _;
        cin >> _;
        while(_--) solve();
}