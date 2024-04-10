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
const int N=2e1+100;
ll vis[N];
ll a[N];
ll Main(){
    ll n,k;
    cin >> n >> k;
    memset(vis,0,sizeof vis);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll cnt=0;
    for (int i=1;i<=n;i++){
        if (vis[a[i]]==0) cnt++;
        vis[a[i]]++;
    }
    if (k==1 && cnt>1) kill(-1);
    if (cnt<=k) kill(1);
    n=cnt;
    if (a[1]==0){
        n--;
        cout << (n+k-2)/(k-1) << endl;
    }
    else{
        n-=k;
        cout << (n+k-2)/(k-1)+1 << endl;
    }
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}