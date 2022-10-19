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
    cin >> n ;
    bool p1=0;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        bool f=0;
        for (int j=1;j<=min((ll)50,i);j++){
            if (a[i]%(j+1)!=0) f=1;
        }
        if (!f) p1=1;
    }
    if (p1) kill("NO");
    kill("YES");
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}