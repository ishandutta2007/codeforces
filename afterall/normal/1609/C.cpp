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

const int N=1e6+100;
ll pr[N];
vector <int> a[N];
int Main(){
    ll n,e;
    cin >> n >> e;
    ll ans=0;
    for (int i=0;i<=e;i++) a[i].clear();
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        a[i%e].pb(x);
    }
    for (int t=0;t<e;t++){
        for (int i=0;i<a[t].size();i++){
            if (pr[a[t][i]]==1) continue;
            ll j=i;
            while(j<a[t].size() && pr[a[t][j]]==0) j++;
            vector <int> c;
            ll l=0;
            for (int k=i;k<j;k++){
                if (a[t][k]==1) l++;
                else{
                    c.pb(l);
                    if (c.size()==1) ans+=l;
                    else ans+=2*l;
                    l=0;
                }
            }
            ans+=l;
            c.pb(l);
            if (c.size()==1) ans-=l;
            for (int k=1;k<c.size();k++){
                ans+=c[k-1]*c[k];
            }

            i=j-1;
        }
    }

    cout << ans << endl;
    return 0;
}
int32_t main(){
    sync;
    pr[1]=0;
    for (int i=2;i<N;i++){
        for (int j=2*i;j<N;j+=i) pr[j]=1;
    }
    ll t;
    cin >> t;
    while(t--) Main();
}