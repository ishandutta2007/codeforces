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
const ll N = 2e5+18;
ll a[N], b[N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i] >> b[i];
        }
        ll l = 1, r = n+1;
        while(r-l>1){
            ll m = (l+r)>>1;
            ll tk=0;
            for(ll i = 0;i<n&&tk<m;i++){
                if(a[i]>=m-tk-1 && b[i]>=tk) ++tk;
            }
            if(tk==m) l=m;
            else r=m;
        }
        cout<<l<<'\n';
    }
}