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
#define kill(x) cout << x << endl;return ;
using namespace std;
const int N=2e5+100;
string s;
ll len[N];
ll L[N];
ll R[N];
char get(ll k,ll i){
   // cout << k << " ijftjn " << i << endl;
    if (i==0){
        return s[k];
    }
    if (k>len[i-1]){
        return get(k-len[i-1]+L[i]-1,i-1);
    }
    else{
        return get(k,i-1);
    }
}
void Main(){
    ll n,c,q;
    cin >> n >> c >> q;
    cin >> s;
    s='.'+s;
    len[0]=n;
    for (int i=1;i<=c;i++){
        cin >> L[i] >> R[i];
        len[i]=len[i-1]+R[i]-L[i]+1;
    }
    while(q--){
        ll x;
        cin >> x;
        cout << get(x,c) << endl;
    }

}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while (t--) Main();
}