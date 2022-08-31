#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  int             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second                
 
const ll   N     =  4e5+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n,a[N],fans,b[N],c[N];
 
int main(){
    fastio;
    cin>>n;
    for(ll i = 0; i < n; i++){
        cin>>a[i];
    }
    for(ll k = 0; k < 25; k++){
        for(int j=0;j<n;j++){
            if(a[j]&(1<<k)) c[j]+=1<<k;
            b[j]=c[j];
        }
        sort(b,b+n);
        ll ct = 0;
        for(ll i = 0; i < n; i++){
            ll x = (1<<k)-c[i], y = (1<<(k+1))-c[i];
            ll l = lower_bound(b,b+n,x)-b, r = lower_bound(b+l,b+n,y)-b;
            ct += r-l;
            if(c[i]>=x&&c[i]<y) ct--;
            x += 1<<(k+1),y += 1<<(k+1);
            l = lower_bound(b,b+n,x)-b,r = lower_bound(b+l,b+n,y)-b;
            ct += r-l;
            if(c[i] >= x && c[i] < y) ct--;
        }
        ct /= 2;
        if(ct&1) fans += (1<<k);
    }
    cout<<fans<<endl;
}