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
const ll N = 5e5+18;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, a, b;
        cin >> n >> a >> b;
        if(a==b){
            if(a*2+2 > n) cout<<"-1\n";
            else{
                ll bls = a+1;
                ll fsz = n-(a+a+2)+2, off=0;
                for(ll B=0;B<bls;B++){
                    ll sz=  (B?2:fsz);
                    for(ll j = off+sz-1;j>=off;j--) cout<<j+1<<' ';
                    off+=sz;
                }
                cout<<'\n';
            }
        }else if(a-1==b){
            //first odin, last full
            if(a+a+1 > n) cout<<"-1\n";
            else{
                cout<<1<<' ';
                ll bls = a;
                ll fsz = n-(a+a+1)+2;
                ll off=1;
                for(ll B=0;B<bls;B++){
                    ll sz=  (B?2:fsz);
                    for(ll j = off+sz-1;j>=off;j--) cout<<j+1<<' ';
                    off+=sz;
                }
                cout<<'\n';
            }
        }else if(a+1==b){
            //first full, last n
            if(b+b+1 > n) cout<<"-1\n";
            else{
                ll bls = b;
                ll fsz = n-(b+b+1)+2;
                ll off=0;
                for(ll B=0;B<bls;B++){
                    ll sz=  (B?2:fsz);
                    for(ll j = off+sz-1;j>=off;j--) cout<<j+1<<' ';
                    off+=sz;
                }
                cout<<n;
                cout<<'\n';
            }
        }else{
            cout<<-1<<'\n';
        }
    }
}