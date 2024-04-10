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
const int N=2e5+100;
ll vis[N];
ll a[N];
map <int,int> mp;
int Main(){
    ll n;
    cin >> n;
    mp.clear();
    for (int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i=0;i<n;i++) if (mp[a[i]]>1 || a[i]==0 || mp[-a[i]]>0) kill("YES");
    ll p3=1;
    for (int i=0;i<n;i++){
        p3*=3;
    }
    for (int i=1;i<p3;i++){
        vector <int> bit;
        ll x=i;
        ll p1=0;
        while(x){
            if (x%3!=0) p1++;
            bit.pb(x%3);
            x/=3;
        }
        ll s=0;
        for (int j=0;j<bit.size();j++){
            if (bit[j]==1) s+=a[j];
            if (bit[j]==2) s-=a[j];
        }
        if (s==0) kill("YES");
    }
    kill("NO");
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}