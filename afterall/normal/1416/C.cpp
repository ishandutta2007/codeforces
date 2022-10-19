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
const int N=3e5+100,lg=32;
ll ts=0,ch[lg*N][2],in[lg][2],cnt[lg*N];
void add(ll val){
    ll now=0;
    for (int i=30;i>=0;i--){
        ll z=val/(1<<i);
        z=z%2;
        if (ch[now][z]==0){
            ch[now][z]=++ts;
            ch[now][1-z]=++ts;
        }
        in[i][z]+=cnt[ch[now][1-z]];
        cnt[ch[now][z]]++;
        now=ch[now][z];
    }
}
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        add(x);
    }
    ll ans=0,mi=0;
    for (int i=30;i>-1;i--){
        if (in[i][0]>in[i][1]){
            mi += (1<<i);
        }
        ans+=min(in[i][0],in[i][1]);
    }
    cout << ans << " " << mi << endl;
}
int32_t main(){
    ll t;
    t=1;
    while(t--) Main();
}