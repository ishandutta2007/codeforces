#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int (i)=(int)(a); (i) < (int)(b); ++(i))
#define mp make_pair
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int,int> pii;
const ll MOD = 1e9+7;

ll inv(ll a,ll m){
    if(a == 1)
        return 1;
    return m - (inv(m%a,a)*m)/a;
}

vl fac, invs;

ll vag(const int &dx, const int &dy){
    if(dx < 0 || dy < 0)
        return 0;
    return ((fac[dx+dy]*invs[dx]%MOD)*invs[dy])%MOD;
}

int main(){
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    fac.resize(h+w-1), invs.resize(max(h,w));
    fac[0] = invs[0] = 1;
    rep(i,1,h+w-1)
        fac[i] = (fac[i-1]*i)%MOD;
    rep(i,1,max(h,w))
        invs[i] = (invs[i-1]*inv(i,MOD))%MOD;
    vi rad(n), kol(n);
    rep(i,0,n)
        scanf("%d %d",&rad[i],&kol[i]);
    vl an(n);
    rep(i,0,n)
        an[i] = vag(rad[i]-1,kol[i]-1);
    vector<pii> hal(n);
    rep(i,0,n)
        hal[i] = mp(rad[i]+kol[i],i);
    sort(hal.begin(),hal.end());
    ll svar = vag(h-1,w-1);
    rep(k,0,n){
        int j = hal[k].second;
        svar -= an[j]*vag(h-rad[j],w-kol[j]);
        svar %= MOD;
        rep(ix,k+1,n){
            int i = hal[ix].second;
            if(i != j){
                an[i] -= an[j]*vag(rad[i]-rad[j],kol[i]-kol[j]);
                an[i] %= MOD;
            }
        }
    }
    if(svar < 0)
        svar += MOD;
    printf("%d\n",(int)svar);
}