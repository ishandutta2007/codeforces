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
const ll M = 1e9+7;

ll a[N], b[N];
ll f[N], of[N];
ll mbc[50];
ll bpm(ll a, ll b){
    a%=M;
    if(b==0) return 1;
    if(b==1) return a;
    if(b&1) return (bpm(a*a, b>>1)*a)%M;
    else return bpm(a*a, b>>1);
}

// ll c(ll n, ll k){
//     return f[n]*of[k]%M*of[n-k]%M;
// }


signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    // f[0]=1;
    // for(ll i = 1;i<N;i++) f[i]=(f[i-1]*i)%M;
    // of[N-1]=bpm(f[N-1], M-2);
    // for(ll i = N-2;i>=0;i--) of[i]=(of[i+1]*(i+1))%M;
    // assert(f[0]*of[0]%M==1);
    ll n, m=0, odd=0;
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
        if(a[i]&1) odd++;
        else b[m++]=(a[i]/2);
    }
    ll res = ((bpm(2, odd)+M-1)%M)*bpm(2, m)%M;
    for(ll i = 0;i<m;i++){
        mbc[__builtin_ctz(b[i])]++;
    }
    ll gg=0;
    for(ll i = 40;i>=0;i--){
        if(!mbc[i]) continue;
        ll fc = bpm(2, mbc[i]-1)+M-1; // C(n, 2) + C(n, 4) + C(n, 6)
        if(fc>=M) fc-=M;
        res+=bpm(2, gg)*fc%M;
        gg+=mbc[i];
    }
    cout<<(res%M);
}