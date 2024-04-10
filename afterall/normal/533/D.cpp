#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e5+100;
ll nxt[N],pre[N];
ll x[N];
ll d[N];
    set <pii> s;
void add(ll v){
    s.insert({x[v]+2*nxt[v],v});
}
void hazf(ll v){
    s.erase({x[v]+2*nxt[v],v});
}
int32_t main(){
    ll n;
    cin >> n ;
    for (int i=0;i<=n+1;i++){
        cin >> x[i];
        x[i]*=2;
    }
    for (int i=1;i<=n;i++){
        cin >> d[i];
        d[i]*=2;
    }
    d[0]=1e9,d[n+1]=1e9;
    vector <int> bk;
    bk.pb(0);
    nxt[0]=d[0];
    for (int i=1;i<=n+1;i++){
        while(bk.size()>1 && (x[i]-x[bk.back()])/2>nxt[bk.back()]){
            bk.pop_back();
        }
        ll v=bk.back();
        if ((x[i]-x[v])/2<d[i]){
            nxt[i]=d[i]-(x[i]-x[v])/2;
            bk.pb(i);
        }
        if (i==n+1 && (x[i]-x[v])/2<d[i] && v) kill(0);

    }
    ll poi1=0;
    for (int i=1;i<=n;i++){
        if (x[i]+nxt[i]>=x[n+1]) poi1=1;
    }
    if (poi1) kill(0);
    pre[n+1]=d[n+1];
    bk.clear();
    bk.pb(n+1);
    for (int i=n;i>0;i--){
        while(bk.size()>1 && (x[bk.back()]-x[i])/2>pre[bk.back()]){
            bk.pop_back();
        }
        ll v=bk.back();
        if ((x[v]-x[i])/2<d[i]){
           // if (i==1) cout << x[v]-x[i] << " jifr " << endl;
            pre[i]=d[i]-(x[v]-x[i])/2;
            bk.pb(i);
        }
    }
    for (int i=1;i<=n;i++){
    //    cout << pre[i] << " " << nxt[i] << endl;
    }
    ll l=0,r=1e9+1;
    while(r-l>1){
        ll mid=(r+l)/2;
        s.clear();
        ll cnt=n+1;
        ll p1=0;
        for (int i=n+1;i;i--){
            if (pre[i]==0) continue;
            cnt=min(cnt,i);
            while(cnt && x[i]-x[cnt-1]<=mid*2){
                cnt--;
               // if (mid==1) cout << i << " " << cnt << endl;
               if (nxt[cnt]!=0)
                add(cnt);
            }
            if (s.size()){
                ll mx=s.rbegin()->F;
                if (mx>=x[i]-2*pre[i]){
                    //if (mid==50) cout << "WTF" << i << endl;
                    p1=1;
                }
            }
            hazf(i-1);
        }
        if (p1) r=mid;
        else l=mid;
    }
    cout << (ld)r/(ld)2 << endl;

}
/// 0 100 200 300 400
///    100 2 100