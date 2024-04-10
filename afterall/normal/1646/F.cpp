#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=110;
vector <int> a[N];
void add(ll x,ll id){
  //  cout << id << " " << x << " ejhrbg " << endl;
    a[id].pb(x);
}
void del(ll x,ll id){
    ll p1=-1;
    for (int i=0;i<a[id].size();i++){
        if (a[id][i]==x){
            p1=i;
        }
    }
    if (p1==-1){
      //  cout << 1/0;
        return ;
    }
    vector <int> b;
    for (int i=0;i<p1;i++){
        b.pb(a[id][i]);
    }
    for (int i=p1+1;i<a[id].size();i++){
        b.pb(a[id][i]);
    }
    a[id]=b;
}
bool check(ll n){
    for (int i=1;i<=n;i++){
        sort(a[i].begin(),a[i].end());
        for (int j=1;j<n;j++){
            if (a[i][j]==a[i][j-1]) return 1;
        }
    }
    return 0;
}
ll c[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            ll x;
            cin >> x;
            a[i].pb(x);
        }
    }
    vector <vector <int> > ans;
    ll o=0;
    while(check(n)){
        o++;
        memset(c,0,sizeof c);
       // if (o>20) break;
        vector <int> b;
        for (int i=1;i<=n;i++){
            ll p1=0;
            sort(a[i].begin(),a[i].end());
            for (int j=1;j<a[i].size();j++){
                if (a[i][j]==a[i][j-1]){
                    ll z=i+1;
                    if (z>n) z-=n;
                    c[i]=a[i][j];
                   // cout << i << " mamad " << a[i][j] << endl;
                    add(a[i][j],z);
                    del(a[i][j],i);
                    p1=1;

                    break;
                }
            }
        }
        for (int i=1;i<=n;i++){
            if (c[i]!=0) continue;
            sort(a[i].begin(),a[i].end());
            ll p1=0;
            for (int j=1;j<a[i].size();j++){
                if (a[i][j]==a[i][j-1]){
                    ll z=i+1;
                    if (z>n) z-=n;
                    c[i]=a[i][j];
                   // cout << i << " mamad " << a[i][j] << endl;
                    add(a[i][j],z);
                    del(a[i][j],i);
                    p1=1;

                    break;
                }
            }
        }
        for (int i=1;i<=n;i++){
            b.pb(c[i]);
        }
        ans.pb(b);
        
        
    }
    if (ans.size()>n*(n-1)/2) cout << 1/0;
    while(true){
        ll id=-1;
        for (int i=2;i<=n;i++){
            for (int j=0;j<n;j++){
                if (a[i][j]==1){
                    id=i;
                }
            }
        }
        if (id==-1) break;
        ll cnt=1;
        for (int j=n;j;j--){
            c[id]=cnt;
            id++;
            cnt++;
            if (id>n) id=1;
        }
        vector <int> b;
        for (int i=1;i<=n;i++) {
            b.pb(c[i]);
            ll z=i+1;
            if (z>n) z-=n;
            add(c[i],z);
            del(c[i],i);
        }
        ans.pb(b);
    }
    /*
    for (int i=1;i<=n;i++){
        for (int j=0;j<n;j++){
            if (a[i][j]!=i) cout << 1/0;
        }
    }
    if (ans.size()>n*n-n) cout << 1/0;
    */
    cout << ans.size() << endl;
    for (auto U : ans){
        for (auto u : U ){
            cout << u << " ";
        }
        cout << endl;
    }

}