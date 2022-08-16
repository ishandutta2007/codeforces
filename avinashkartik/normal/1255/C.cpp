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

const ll   N  =  1e+5+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,k1,vis[N],a[N][3],b[N],d[N],no[N];
vll v[N];

int main(){
    fastio;
    cin>>n;
    for(int i = 0; i < n-2; i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        b[a[i][0]]++;
        b[a[i][1]]++;
        b[a[i][2]]++;
        v[a[i][0]].push_back(i);
        v[a[i][1]].push_back(i);
        v[a[i][2]].push_back(i);
    }
    ll ind = 3;
    for(int i = 1; i <= n; i++){
        if(b[i] == 1){k1=v[i][0];break;}
    }
    for(int i = 0; i < 3; i++){
        ll j = b[a[k1][i]]-1;
        d[j] = a[k1][i];
        no[a[k1][i]] = 1;
    }
    vis[k1] = 1;
    k1 = d[1];
    ll k2;
    while(ind < n){
        for(auto it : v[k1]){
            //cout<<k1<<" ";
            if(!vis[it]){
                vis[it] = 1;
                for(int i = 0; i < 3; i++){
                    if(!no[a[it][i]]){
                        no[a[it][i]] = 1;
                        //cout<<it<<" "<<a[it][i]<<endl;
                        k2 = d[ind-1];
                        d[ind++] = a[it][i];
                    }
                }
            }
        }
        k1 = k2;
    }
    for(int i = 0; i < n; i++)cout<<d[i]<<" ";
}