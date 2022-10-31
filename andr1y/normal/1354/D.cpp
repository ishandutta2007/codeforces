//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6+228;
int fwt[N];
void fwinc(ll p, ll d=1){
    for(;p<N;p+=p&-p)fwt[p]+=d;
}
ll get(ll e){
    ll ns=0, np=0;
    for(ll L = 19;L>=0;L--){
        if(fwt[np+(1<<L)]<e){
            np+=1<<L;
            e-=fwt[np];
        }
    }
    return np;
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, q, a, sz=0;
    cin >> n >> q;
    sz=n;
    while(n--){cin>>a;fwinc(a);}
    while(q--){
        ll e;
        cin >> e;
        if(e>0){
            fwinc(e);
            sz++;
        }else{
            e=-e;
            ll np = get(e);
            fwinc(np+1, -1);
            sz--;
        }
    }
    if(sz==0)cout<<0;
    else cout<<get(1)+1;
}