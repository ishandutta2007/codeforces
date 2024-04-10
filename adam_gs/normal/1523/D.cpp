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
const int LIM=2e5+7;
ll maski[LIM], ile[1<<16], ile2[1<<16];
ll ilebitow(ll x) {
        ll ans=0;
        while(x) {
                ans+=x&1;
                x/=2;
        }
        return ans;
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        srand(time(NULL));
        ll n, m, p;
        cin >> n >> m >> p;
        rep(i, n) {
                string x;
                cin >> x;
                rep(j, m) if(x[j]=='1') maski[i]+=1ll<<j;
        }
        ll ans=0;
        rep(_, 25) {
                ll a=rand()%n, b=rand()%n;
                ll x=a*b; x%=n;
                vector<ll>bity;
                rep(i, m) if(maski[x]&(1ll<<i)) bity.pb(i);
                rep(i, 1<<bity.size()) ile[i]=ile2[i]=0;
                rep(i, n) {
                        ll p=0;
                        rep(j, bity.size()) if(maski[i]&(1ll<<bity[j])) p+=(1ll<<j);
                                                ++ile2[p];
                }
                                rep(i, 1<<bity.size()) {
                                        if(!ile2[i]) continue;
                                        for(int s=i; s; s=(s-1)&i) ile[s]+=ile2[i];
                                }
                rep(i, 1<<bity.size()) if(ile[i]>=(n+1)/2) {
                        if(ilebitow(ans)<ilebitow(i)) {
                                ll p=0;
                                rep(j, bity.size()) if(i&(1ll<<j)) p+=(1ll<<bity[j]);
                                ans=p;
                        }
                }
        }
        rep(i, m) cout << (ans&(1ll<<i)?1:0);
}