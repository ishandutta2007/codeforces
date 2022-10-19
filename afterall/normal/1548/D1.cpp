#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
ll a[2][2];
ll ent(ll k,ll n){
    ll ans=1;
    if (k>n) return 0;
    for (int i=n;i>n-k;i--){
        ans*=i;
    }
    for (int i=1;i<=k;i++) ans/=i;
    return ans;
}
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=0;i<n;i++){
        ll x,y;
        cin >> x >> y;
        x=x%4;
        y=y%4;
        if (x==2) x--;
        if (y==2) y--;
        a[x][y]++;
    }
    ll jav=0;
    for (int i=0;i<=3;i++){
        for (int j=0;j<=3;j++){
            for (int k=0;k<=3;k++){
                for (int l=0;l<=3;l++){
                    if (i+j+k+l!=3) continue;
                    ll ans=1;
                    vector <int> aa;
                    aa.pb(i);
                    aa.pb(j);
                    aa.pb(k);
                    aa.pb(l);
                    ll cnt=0;
                    for (int p=1;p<aa.size();p++){
                        for (int u=0;u<p;u++){
                            cnt+=aa[p]*aa[u];
                        }
                    }
                    ans*=ent(i,a[0][0]);
                    ans*=ent(j,a[0][1])*ent(k,a[1][0])*ent(l,a[1][1]);
                    if (cnt%2==0) jav+=ans;

                }
            }
        }
    }
    kill(jav);
}