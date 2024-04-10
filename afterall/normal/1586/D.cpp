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
const int N=2e5+100;
ll nxt[N];
ll bf[N];
ll n;
ll ask(ll x,bool p){
    if (p==0){
        cout << "? ";
        for (int i=1;i<=n;i++){
            if (i!=x) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << endl;
        ll ans;
        cin >> ans;
        return ans;
    }
    cout << "? ";
        for (int i=1;i<=n;i++){
            if (i!=x) cout << 2 << " ";
            else cout << 1 << " ";
        }
    cout << endl;
    ll ans;
    cin >> ans;
    return ans;
}
ll jav[N];
int Main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        ll ans=ask(i,0);
        if (ans!=0 && ans!=i){
            bf[ans]=i;
            nxt[i]=ans;
          //  cout << i << " ans " << ans << endl;
        }
        ans=ask(i,1);
        if (ans!=0 && ans!=i){
            nxt[ans]=i;
            bf[i]=ans;
           // cout << ans << " ans " << i << endl;
        }
    }
    ll id=0;
    for (int i=1;i<=n;i++){
        if (bf[i]==0) id=i;
    }
    ll cnt=0;
    while(nxt[id]!=0){
        jav[id]=cnt+1;
        cnt++;
        id=nxt[id];
    }
    jav[id]=cnt+1;
    cout << "! ";
    for (int i=1;i<=n;i++){
        cout << jav[i] << " ";
    }
    cout << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
   // cin >> t;
    while(t--) Main();
}
/*
1
1
1
2

2

0

0

4

4

1
*/