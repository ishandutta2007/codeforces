#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an lleratcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<string,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second
#define  endl                  "\n"                
 
const ll   N     =  1e+5+7;
const ll   MAXN  =  1e+9;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll te,n,m;
string s,t;
set <ll> se[26];

int main(){
    fastio;
    cin>>te;
    while(te--){
        cin>>s>>t;
        int flag = 1;
        ll ct = 1;
        n = s.size();
        for(int i = 0; i < n; i++){
            ll ind = s[i] - 'a';
            se[ind].insert(i);
        }
        m = t.size();
        ll prev = 0;
        for(int i = 0; i < m; i++){
            ll ind = t[i] - 'a';
            if(se[ind].size() == 0){
                flag = 0;break;
            }
            auto it = se[ind].lower_bound(prev);
            if(it == se[ind].end()) ct++,it = se[ind].lower_bound(0);
            prev = (*it)+1;
        }
        if(flag == 0) cout<<-1<<endl;
        else cout<<ct<<endl;
        for(int i = 0; i < 26; i++) se[i].clear();
    }
}