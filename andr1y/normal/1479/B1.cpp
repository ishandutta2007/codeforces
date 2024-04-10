// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], bc=0, cc=0;
pll b[N];
pll c[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll t1=0, t0=0, r=0;
    for(ll i =0;i<n;i++) cin>>a[i];
    for(ll i =0;i<n;i++){
        if(i&&a[i]==a[i-1]) b[bc-1].y++;
        else{
            b[bc]={a[i], 1};
            bc++;
        }
    }
    for(ll i = 0;i<bc;i++){
        if(i&&b[i].y==1&&b[i-1].y==1){
            c[cc-1].y--;
        }else{
            c[cc]={b[i].x, b[i].y==1 ? -1 : b[i].y};
            cc++;
        }
    }
    bool a0=1;
    ll off=0;
    for(ll i = 0;i<cc;i++){
        if(c[i].y>1){
            r+=(t0!=c[i].x);
            r+=(t1!=c[i].x);
            t0=c[i].x, t1=c[i].x;
            off+=c[i].y;
        }else{
            ll bf = t0, nx = (i+1<cc?c[i+1].x:-1);
            ll to = off-c[i].y;
            ll sz = -c[i].y;
            if(bf!=nx){
                r+=sz;
                t0=a[to-1];
            }else{
                bool cn=0;
                ll k0=0;
                for(ll ch=off+1;ch+1<to;ch++){
                    if(a[ch-1]!=a[ch+1]&&a[ch]!=nx) cn=1, k0=a[ch];
                }
                if(sz>1&&a[to-2]!=nx&&!cn){
                    cn=1, k0=to-1;
                }
                if(cn) t0=a[to-1], t1=k0, r+=sz;
                else{
                    r+=sz;
                    t0=a[to-1];
                }
            }
            off+=-c[i].y;
        }
    }
    cout<<r;
}