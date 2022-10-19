//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <string>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <limits.h>
#include <tuple>
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
const int N=2e5+100;
ll c[N];
void Main(){
    vector <int> a,b;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> c[i];
    }
    for (int i=1;i<=n;i++){
        ll x;
        cin >> x;
        if (c[i]==0) a.pb(x);
        else b.pb(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if (a.size()<b.size()) swap(a,b);
    vector <int> d;
    ll ans=0;
    for (int i=0;i<b.size();i++){
        d.pb(a[i]);
        d.pb(b[i]);
        ans+=(a[i]+b[i])*2;
    }
    if (a.size()>b.size()){
       // ans+=a[b.size()]*2;
        for (int i=b.size();i<a.size();i++) ans+=a[i];
    }
    else {
        ans-=min(a.back(),b.back());
    }
    cout << ans << endl;
    
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}