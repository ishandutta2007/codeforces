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
const int N=3e5+100;
ll a[N];
ll mx[N];
int32_t main(){
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    if (n==1) kill(a[1]);
    if (n==2){
        cout << max(a[1],a[2]) << " " << max(a[1],a[2]) << endl;
        return 0;
    }
    ll p1=0,p2=0,p3=0;
    for (int i=1;i<n;i++){
        p3=max(p3,max(a[i],a[i+1]));
        ll x=max(a[i],a[i+1]);
        p1=max(p1,x);
        ll l=i-1,r=n-i-1;
        mx[abs(l-r)]=max(mx[abs(l-r)],x);
    }
    for (int i=1;i<n-1;i++){
        ll x=min(a[i+1],max(a[i],a[i+2]));
        p2=max(p2,x);
        ll l=i-1,r=n-i-2;
        mx[abs(l-r)]=max(mx[abs(l-r)],x);
    }
    for (int i=0;i<n-3;i++){
        if (i-2>=0){
            mx[i]=max(mx[i],mx[i-2]);
        }
        cout << mx[i] << " ";
    }
    cout << p2 << " " << p1 << " " << p3 << endl;
}