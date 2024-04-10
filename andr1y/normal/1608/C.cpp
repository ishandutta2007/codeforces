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
const ll N = 1e5+18;

pll a[N];
yree ta, tb;
ll pa[N], pb[N];
char res[N];
typedef unsigned long long ull;
typedef pair<ull, ull> pull;
const ull P = 2;
const ull M1 = 998244353;
const ull M2 = 1014881489;
pull p[N];

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    p[0] = {1, 1};
    for(ll i = 1;i<N;i++) p[i].x = p[i-1].x*P%M1, p[i].y = p[i-1].y*P%M2;
    ll q;
    cin >> q;
    while(q--){
        ta.clear(), tb.clear();
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++) {
            cin >> a[i].x;
        }
        for(ll i = 0;i<n;i++){
            cin >> a[i].y;
            ta.insert(a[i].x), tb.insert(a[i].y);
            res[i]='0';
        }
        for(ll i = 0;i<n;i++){
            //a[i].x = ta.order_of_key(a[i].x);
            //a[i].y = tb.order_of_key(a[i].y);
            pa[ta.order_of_key(a[i].x)] = i;
            pb[tb.order_of_key(a[i].y)] = i;
        }
        pull h1 = {0, 0}, h2={0, 0};
        for(ll i = n-1;i>=0;i--){
            h1.x+=p[pa[i]].x;
            h1.y+=p[pa[i]].y;
            h1.x%=M1, h1.y%=M2;
            h2.x+=p[pb[i]].x;
            h2.y+=p[pb[i]].y;
            h2.x%=M1, h2.y%=M2;
            res[pa[i]]='1';
            //cout<<h1.x << ' ' <<h1.y<<' '<<h2.x << ' '<<h2.y<<' '<<pa[i]<<' '<<pb[i]<<'\n';
            if(h1==h2) break;
        }
        for(ll i = 0;i<n;i++) cout<<res[i];
        cout<<'\n';
    }
}