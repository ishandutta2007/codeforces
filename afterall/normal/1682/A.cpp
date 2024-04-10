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
ll a[N];
ll b[N];
ll par[N];
ll sig[N];
ll mod=109+7;
ll getcnt(ll l,ll r){
    return par[r]-par[l-1];
}
map <int,int> mp,pm;
void Main(){
    string s;
    ll n;
    cin >> n;
    cin >> s;
    //ll n=s.size();
    ll ans=0;
    for (int i=n/2;i<n;i++){
        if (s[i]==s[n/2]) ans++;
        else break;
    }
    for (int i=n/2-1;i>-1;i--){
        if (s[i]==s[n/2]) ans++;
        else break;
    }
    cout << ans << endl;


}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}