#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) cout<<x<<'\n';
using namespace std;
void Main(){
    ll n;
    cin >> n;
    vector <int> a;
    ll x=-1e9-100;
    ll p1=0;
    for (int i=1;i<=n;i++){
        ll d;
        cin >> d;
        if (d<x){
            p1=1;
        }
        x=d;
    } 
    if (p1) kill("YES")
    else kill("NO");
}
int32_t main(){
    sync;
    int t=1;
    cin >> t;
    while(t--) Main();
}