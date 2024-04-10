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
void Main(){
    ll n,k;
    for (int i=0;i<26;i++) a[i]=0;
    cin >> n >> k;
    k=n/k;
    string s;
    cin >> s;
    for (int i=0;i<n;i++){
        a[s[i]-'a']++;
    }
    string ans="";
    for (int i=0;i<n/k;i++){
        ll cnt=0;
        ll p1=k;
        for (int j=0;j<26;j++){
            if (a[j]==0) p1=min(p1,j);
            if (cnt<k && a[j]>0){
                cnt++;
                a[j]--;
            }
        }
        ans+=(char)('a'+p1);
    }
    cout << ans << endl;
    
}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();

    
}