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
ll a[26];
ll getUpper(ll n,ll k){
    ll z=sqrt(n);
    for (int i=max((ll)1,z-20);i<=z+20;i++){
        if (i*(i+k)>n) return i;
    }
    return -1;
}
ll getLower(ll n,ll k){
    ll z=sqrt(n);
    for (int i=max((ll)1,z-20);i<=z+20;i++){
        if (i*(i+k)>=n) return i;
    }
    return -1;
}
void Main(){
    ll l,r;
    cin >> l >> r;
    ll ans=0;
    for (int i=0;i<=2;i++){
        ll L=getLower(l, i);
        ll R=getUpper(r, i);
        ans+=R-L;
    }
    cout << ans << endl;
    
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();

    
}