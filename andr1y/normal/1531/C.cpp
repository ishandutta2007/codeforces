// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100;
char r2[N][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    if(n==2) return cout<<-1, 0;
    ll res=n, ob=1;
    for(ll base=1;base*base<=n;base++){
        ll e = n-base*base;
        if(e&1) continue;
        ll u = base + ((e/2)+base-1)/base;
        if(u<=res)res=u, ob=base;
    }
    cout<<res<<'\n';
    memset(r2, '.', sizeof r2);
    for(ll i =0;i<ob;i++){
        for(ll j = 0;j<ob;j++) r2[i][j]='o';
    }
    ll lft = (n-ob*ob)/2;
    for(ll jj = 0;jj<lft;jj++){
        ll i = ob+jj/ob;
        ll j = jj%ob;
        r2[i][j]='o';
        r2[j][i]='o';
    }
    for(ll i = res-1;i>=0;i--){
        for(ll j = 0;j<res;j++) cout<<r2[i][j];
        cout<<'\n';
    }
}