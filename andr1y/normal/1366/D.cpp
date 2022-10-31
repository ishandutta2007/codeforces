//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7+228;
ll lp[N];
ll cp[N];
ll d1[500500], d2[500500];
vector<ll> pr;
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	ll n;
	cin >> n;
    for (ll i=2; i<N; i++){
        if (lp[i] == 0){
            lp[i]=i;
            cp[i]=i;
            pr.push_back(i);
        }
        for(auto j : pr){
            if(j>lp[i]||i*j>N) break;
            lp[i*j]=j;
            cp[i*j]=(lp[i]==j?cp[i]*j:j);
        }
    }
    for(ll i = 0, a;i<n;i++){
        cin >> a;
        ll v1 = cp[a], v2 = a/cp[a];
        if(v1==1||v2==1||__gcd(v1+v2, a)!=1) d1[i]=d2[i]=-1;
        else d1[i]=v1, d2[i]=v2;
    }
    for(ll i = 0, a;i<n;i++) cout<<d1[i]<<' ';
    cout<<'\n';
    for(ll i = 0, a;i<n;i++) cout<<d2[i]<<' ';
}