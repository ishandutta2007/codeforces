#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=3e5+100;
ll ans[N];
ll W;
ll nott(ll x){
    return (1<<W)-1-x;
}
void Main(){
    ll n,k;
    cin >> n >> k;
    for (int i=0;i<20;i++){
        if ((1<<i)==n) W=i;
    }
    for (int i=0;i<n;i++) ans[i]=-1;
    if (k!=n-1){
        ll z=nott(k);
        ans[0]=z;
        ans[z]=0;
       // cout << k << " rfn " << nott(k) << endl;
        ans[nott(z)]=nott(0);
        ans[nott(0)]=nott(z);
        for (int i=0;i<n;i++){
            if (ans[i]==-1) ans[i]=(nott(i));
        }
    }
    else{
        
        if (W<=2){
            cout << -1 << endl;
            return ;
        }
        ans[0]=(1<<(W-1));
        ans[(1<<(W-1))]=0;
        ans[(1<<W)-1]=(1<<(W-1))-1;
        ans[(1<<(W-1))-1]=(1<<W)-1;
        ans[(1<<W)-1-(1<<(W-2))]=(1<<(W-1))+(1<<(W-2));
        ans[(1<<(W-1))+(1<<(W-2))]=(1<<W)-1-(1<<(W-2));
        ans[nott((1<<W)-1-(1<<(W-2)))]=nott((1<<(W-1))+(1<<(W-2)));
        ans[nott((1<<(W-1))+(1<<(W-2)))]=nott((1<<W)-1-(1<<(W-2)));
        for (int i=0;i<n;i++){
            if (ans[i]==-1) ans[i]=nott(i);
        }
    }
    for (int i=0;i<n;i++){
        if (ans[ans[i]]!=-1){
            cout << i << " " << ans[i] << endl;
            ans[i]=-1;
        }
    }
    cout << endl;
    return ;
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}