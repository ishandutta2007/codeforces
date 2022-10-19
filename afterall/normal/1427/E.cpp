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
const int N=63;
ll p[N];
vector <pair <int,pair <char,int> > > ans;
void shift(ll v){
    ans.pb({v,{'+',v}});
    //cout << v << " + " << v << endl;
}
ll solve(ll z,ll id){
    for (int i=0;i<id-1;i++){
    shift(z);
    z*=2;
    }
    ll d=0;
    for (int i=id;i<N;i++){
        if ((z & p[i])>0){
                if (d!=0)
                    ans.pb({d,{'+',p[i]}});
          //  cout << d << " + " << p[i] << endl;
            d+=p[i];
        }
    }
    ans.pb({d,{'^',z}});
  //  cout << d << " ^ " << z << endl;
}
int Main(){
    ans.clear();
    ll x;
    cin >> x;
    ll oo=x;
    p[0]=1;
    for (int i=1;i<N;i++){
        p[i]=p[i-1]*2;
    }
    ll mx=0;
    for (int i=0;i<N;i++) if (p[i]<=x) mx=i;
    ll w=x;
    for (int i=1;i<mx+1;i++){
        shift(w);
        w*=2;
    }
    ll z=w + x;
    ans.pb({w,{'+',x}});
    //cout << w << " + " << x << endl;
    ll e=z ^ x;
//cout << z << " ^ " << x << endl;
    ans.pb({z,{'^',x}});
   // cout << e << " ^ " << w << endl;
    ans.pb({e,{'^',w}});
    e=e^w;
  //  cout << e << " + " << e << endl;
    ans.pb({e,{'+',e}});
    ll r=2*e;
  //  cout << r << " ^ " << e << endl;
    ans.pb({r,{'^',e}});
    r=r ^ e;
  //  cout << r << " + " << e << endl;
  ans.pb({r,{'+',e}});
    r+=e;
    ll p1=0;
   // if (!p1) cout << 1/0;
    //cout << r << endl;
    ll id=0;
    for (int i=0;i<N;i++){
        if (r==p[i]) id=i;
    }
    for (int i=id;i<N-1;i++){
        ans.pb({p[i],{'+',p[i]}});
       // cout << p[i] << " + " << p[i] << endl;
    }
   // cout << endl;
    //cout << p[id] << endl;
    while(id!=0){
        solve(oo,id);
        id--;
    }
    cout << ans.size() << endl;
    for (auto u : ans){
        cout << u.F << " " << u.S.F << " " << u.S.S << endl;
    }

}
int32_t main(){
    sync;
    ll t;
    t=1;
    while(t--) Main();
}