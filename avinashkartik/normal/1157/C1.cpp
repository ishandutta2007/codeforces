#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N  =  2e+5+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,a[N],ind;
vector <char> ans;
char ch;

int main(){
    fastio;
    cin>>n;
    for(int j = 0; j < n; j++) cin>>a[j];
    ll l = 0, r = n-1, ct = 0, prev = -1;
    while(l <= r){
        if(a[l] > a[r] && a[r] > prev){
            ans.push_back('R');
            ct++;
            prev = a[r];
            r--;
        }
        else if(a[l] < a[r] && a[l] > prev){
            ans.push_back('L');
            ct++;
            prev = a[l];
            l++;
        }
        else if(a[l] > prev){
            ans.push_back('L');
            ct++;
            prev = a[l];
            l++;
        }
        else if(a[r] > prev){
            ans.push_back('R');
            ct++;
            prev = a[r];
            r--;
        }
        else break;

    }
    cout<<ct<<endl;
    for(auto it : ans) cout<<it;
    cout<<endl;
}