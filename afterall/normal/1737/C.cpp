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
map<pii,int> mp;
ll get(ll x,ll y){
    ll cnt=mp[{x,y}]+mp[{x-1,y}]+mp[{x+1,y}]+mp[{x,y-1}]+mp[{x,y+1}];
    if (cnt==3) return 1;
    return 0;
}
void Main(){
    mp.clear();
    ll  r1,c1,r2,c2,r3,c3,x,y,n;
    cin >> n >> r1 >> c1 >> r2 >> c2 >> r3 >> c3 >> x >> y;
    mp[{r1,c1}]=1;
    mp[{r2,c2}]=1;
    mp[{r3,c3}]=1;
    
    
    
        if (get(1,1)){
            if (y==1 || x==1){
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            return ;
        }
        if (get(1,n)){
            if (y==n || x==1){
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            return ;
            
        }
        if (get(n,1)){
            if (y==1 || x==n){
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            return ;
        }
        if (get(n,n)){
            if (y==n || x==n){
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            return ;
        }
   
    
    x%=2;
    y%=2;
    r1%=2;
    r2%=2;
    r3%=2;
    c1%=2;
    c2%=2;
    c3%=2;
    
    if ((x==r1 && y==c1) || (x==r2 && y==c2) || (x==r3 && y==c3)){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();

    
}
/*
 1
 3
 1 1 1 2 2 2
 2 3
 */