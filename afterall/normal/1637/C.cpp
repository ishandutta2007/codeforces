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
ll a[N];
int Main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    if (n==3 && a[2]%2==1) kill(-1);
    ll p1=0;
    for (int i=2;i<n;i++) if (a[i]!=1) p1=1;
    if (!p1) kill(-1);
    ll ans=0;
    p1=0;
    for (int i=2;i<n;i++){
        ans+=a[i];
        p1+=a[i]%2;
    }
    ans+=p1;
    kill(ans/2); 
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc --) Main();
    return 0;
}