/*
 _  _    _  _  ____  _  _  ____    _  _  ____  ____    ____  ____   __  ____   __   ____  _  _ 
( \/ )  ( \/ )(  __)/ )( \/ _  )  / )( \(  __)(_  _)  /    \(  _ \ /  \(  __) /  \ (  __)( \/ )
 )  /   / \/ \ ) _) ) __ (\    \  ) __ ( ) _)   )(    ) /\ ( ) __/(  O )) _ \/ /\ \ ) _) / \/ \
(__/    \_)(_/(____)\_)(_/(_/__/  \_)(_/(____) (__)   \_)(_/(__)   \__/(____/\_)(_/(____)\_)(_/
 __ _  ____   __   _  _  ____    _  _   __  ____  _ u_    ____   __   _ _   __ _  _ __         
(  / )(  _ \ /  \ ( \/ )(  __)  ( \/ ) /  \(  __)/ )  )  (  __) / _\ ( ) ))(  / )/ )  )        
 )  (  ) __/(  O )/ \/ \ ) _)   / \/ \(  O )) _) \    \   ) _ \/    \/( ( \ )  ( \    \        
(__\_)(__)   \__/ \_)(_/(____)  \_)(_/ \__/(____)(__(_/  (____/\_/\_/\____/(__\_)(__(_/        
  __   __    __    __       ____                                                               
 /  \ /  \  /  \  /  \  ___(__  )                                                              
(_/ /(  0 )(  0 )(  0 )(___) / /                                                               
 (__) \__/  \__/  \__/      (_/                                                                
 ____    _  _  _  _  ____  ____    ____  ____   __    ___  ____  _ __                          
/ _  )  ( \/ )( \/ )(  __)(  _ \  /    \(  _ \ /  \  / __)(_  _)/ )  )                         
\    \   )  / / \/ \ ) _)  ) __/  ) /\ ( ) __/(  O )( (__   )(  \    \ _  _  _                 
(_/__/  (__/  \_)(_/(____)(__)    \_)(_/(__)   \__/  \___) (__) (__(_/(_)(_)(_)                

(c) 255.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ld inf = 0x3fff3fff3fff3fff;
const ll N = 1e6+18;
vector<ll> d[N];
ll was[N], wc=0;
char type[N];
void dfs(ll v){
    was[v]=wc;
    ll go=0;
    for(auto i : d[v]){
        if(type[i]!='+' && was[i]<wc) go++;
    }
    if(go>1) return;
    type[v]='+';
    for(auto i : d[v]){
        if(type[i]!='+' && was[i]<wc) dfs(i);
    }
}

char a[2][N];

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n*m;i++){
            was[i]=0, d[i].clear();
        }
        vector<ll> ts;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cin >> a[i&1][j];
                type[i*m+j]=a[i&1][j];
                if(i && a[i&1][j]=='.' && a[~i&1][j]=='.') d[i*m+j].push_back(i*m+j-m), d[i*m+j-m].push_back(i*m+j);
                if(j && a[i&1][j]=='.' && a[i&1][j-1]=='.') d[i*m+j].push_back(i*m+j-1), d[i*m+j-1].push_back(i*m+j);
                if(i && a[i&1][j]=='L' && a[~i&1][j]=='.') ts.push_back(i*m+j-m);
                if(i && a[i&1][j]=='.' && a[~i&1][j]=='L') ts.push_back(i*m+j);
                if(j && a[i&1][j]=='L' && a[i&1][j-1]=='.') ts.push_back(i*m+j-1);
                if(j && a[i&1][j]=='.' && a[i&1][j-1]=='L') ts.push_back(i*m+j);
            }
        }
        for(auto i : ts) wc++, dfs(i);
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cout<<type[i*m+j];
            }
            cout<<'\n';
        }
    }
}