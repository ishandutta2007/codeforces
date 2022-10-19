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
ll a[N];
ll par[N];
void Main(){
    ll n,k;
    cin >> n >> k;
    ll id=n-k+1;
    for (int i=1;i<=k;i++){
        ll x;
        cin >> x;
        par[i+n-k]=x;
    }
    if (k==1){
        cout << "YES" << endl;
        return ;
    }
    for (int i=id+1;i<=n;i++){
        a[i]=par[i]-par[i-1];
    }
    for (int i=id+2;i<=n;i++){
        if (a[i]<a[i-1]){
            cout << "NO" << endl;
            return ;
        }
    }
    if (a[id+1]*id<par[id]){
        cout << "NO" << endl;
        return ;
    }
    cout << "YES" << endl;
    return ;
    
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}