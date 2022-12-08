#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
#define pii pair<ll,ll>

using namespace :: std;

const ll maxn=2e5+1000;
const ll mod=1e9+7;
const ll inf=1e9+500;
int di;
vector<pair<ll,pii> > vec;
ll x,y;
ll base=1;
void hesab(ll i){
    di++;
    if(i==1){
        return;
    }
        if(x%i==0 || y%i==0 ){
            di++;
            ll v1=1;
            ll v2=1;
            while(x%i==0){
                di++;
                v1*=i;
                x/=i;
                di++;
            }
            while(y%i==0){
                v2*=i;
                di++;
                y/=i;
            }
            if(v2<v1){
                cout<<0;
                di++;
                exit(0);
            }
            if(v1==v2){
                base*=v1;
                di++;
                return;
            }
            vec.pb(mp(i,mp(min(v1,v2),max(v1,v2))));
        }
}
int main(){
    ll l,r,ans=0;
    di++;
    cin>>l>>r>>x>>y;
    for(ll i=2;i*i<=inf;i++){
        hesab(i);
        di++;
    }
    if(x!=1){
        di++;
        hesab(x);
    }
    if(y!=1){
        di++;
        hesab(y);
    }
    ll m=vec.size();
    for(ll i=0;i<(1<<m);i++){
        ll a=base;
        di++;
        ll b=base;
        for(ll j=0;j<m;j++){
            di++;
            if((i>>j)&1){
                a*=vec[j].S.F;
                b*=vec[j].S.S;
                di++;
            }else{
                b*=vec[j].S.F;
                a*=vec[j].S.S;
                di++;
            }
        }
        if(l<=a && l<=b && a<=r && b<=r){
            ans++;
            di++;
        }
    }
    cout<<ans;
    return 0;
}