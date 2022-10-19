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
#define kill(x) cout << x << endl;return;
using namespace std;
const int N=2e5+100;
ll a[N];
map <int,int> mp;
void Main(){
    ll n,k;
    cin >> n >> k;
    mp.clear();
    for (int i=1;i<=n;i++){
        cin >> a[i];
        mp[a[i]]=i;
    }
    ll x=0;ll y=0;
    for (int i=1;i<=n;i++){
        if (mp[a[i]+k]!=0){
            x=i;
            y=mp[a[i]+k];
            break;
        }
    }
    if (x==0){
        cout << "NO" << endl;return;
    }
    cout << "YES" << endl;return;
    /*
    for (int i=1;i<=n;i++){
        if (i!=x && i!=y) cout << i << " ";
    }
    cout << x << " " << y << endl;
    */
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}