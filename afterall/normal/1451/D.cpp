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
const int N=1e5+100;
int Main(){
    ll n,d;
    cin >> d >> n;
    ll p1=0;
    ll x=0,y=0;
    for (int i=0;i<1e5;i++){
        x+=n;
        if (x*x+y*y>d*d) {
                p1=1;
                break;
        }
        y+=n;
        if (x*x+y*y>d*d) {
                p1=0;
                break;
        }
    }
    if (p1) kill("Utkarsh")
    else kill("Ashish");
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}