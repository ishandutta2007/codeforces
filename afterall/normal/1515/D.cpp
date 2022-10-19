#include <bits/stdc++.h>
/// 500 485 462 A4
/// yani mishe?
using namespace std;
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+100;
vector <int> c[N][2];
ll val[N][2];
int Main(){
    ll n,l,r;
    cin >> n >> l >> r;
    for (int i=1;i<=n;i++) c[i][0].clear(),c[i][1].clear();
    for (int i=1;i<=l;i++){
        ll x;
        cin >> x;
        c[x][0].pb(i);
    }
    for (int i=1;i<=r;i++){
        ll x;
        cin >> x;
        c[x][1].pb(i);
    }
    ll ans=0;
    ll tl=0,tr=0;
    for (int i=1;i<=n;i++){
        val[i][0]=c[i][0].size();
        val[i][1]=c[i][1].size();
        if ((c[i][0].size()+c[i][1].size())%2==1){
            if (c[i][0].size()>c[i][1].size()) tl++,val[i][0]--;
            else tr++,val[i][1]--;
        }
    }
    ll z=min(tl,tr);
    ans+=z;
    tl-=z;
    tr-=z;
  //  cout << tl << " " << tr << endl;
    for (int i=1;i<=n;i++){
        while(val[i][1]>val[i][0] && tl>0){
            tl--;
            val[i][1]--;
            ans++;
        }
        while(val[i][0]>val[i][1] && tr>0){
            tr--;
            val[i][0]--;
            ans++;
        }
      //  cout << i << " " << val[i][0] << " val " << val[i][1] << endl;
        ll z=abs(val[i][0]-val[i][1]);
        ans+=z/2;
    }
    ans+=tl+tr;
    cout << ans << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) {
        Main();
    }
}