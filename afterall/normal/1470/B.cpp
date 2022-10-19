#include <bits/stdc++.h>
/// 500 485 462 A4
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+100;
int val[N];
int bk[N];
bool vis[N];
ll cnt=0;
int Main(){
    ll n;
    cin >> n;
    vector <int> a;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.pb(val[x]);
    }
    sort(a.begin(),a.end());
    ll ans0=0,ans=0;
    for (int i=0;i<a.size();i++){
        ll k=i;
        while(k<a.size() && a[k]==a[i]) k++,cnt++;
        if (cnt>5e6) cout << 1/0;
        ans0=max(ans0,k-i);
        if (a[i]==1 || (k-i)%2==0){
            ans+=k-i;
        }
        i=k-1;
    }
    ll q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;
        if (x==0) cout << ans0 << endl;
        else cout << max(ans0,ans) << endl;
    }
}
int32_t main(){
    sync;
    val[1]=1;
    for (int i=2;i<N;i++){
        if (vis[i]) continue;
        val[i]=i;
        if (i<1e4){
            for (int j=i*i;j<N;j+=i){
                vis[j]=1;
                bk[j]=i;
            }
        }
    }
    for (int i=1;i<N;i++){
        if (val[i]) continue;
        val[i]=val[i/bk[i]];
      //  if (i<=20) cout << " bk " << bk[i] << " " << val[i/bk[i]] << endl;
        if (val[i]%bk[i]!=0) val[i]*=bk[i];
        else val[i]/=bk[i];
        //if (i<10)
       // cout << i << " ern " << val[i] << endl;;
    }
    ll t=1;
    cin >> t;
    while(t--) Main();
}