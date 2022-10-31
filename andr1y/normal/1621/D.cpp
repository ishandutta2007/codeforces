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
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 505;

ll pf[N][N];


ll sum(ll i1, ll i2, ll j1, ll j2){
    if(i1 > i2 || j1 > j2) return 0;
    return pf[i2][j2] - pf[i1-1][j2] - pf[i2][j1-1] + pf[i1-1][j1-1];
}
ll sumrow(ll i, ll j1, ll j2){
    return sum(i, i, j1, j2);
}
ll sumcol(ll j, ll i1, ll i2){
    return sum(i1, i2, j, j);
}
ll sumone(ll i, ll j){
    return sum(i, i, j, j);
}

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll S=0, v = inf;
        for(ll i = 1;i<=n+n;i++){
            for(ll j = 1;j<=n+n;j++){
                ll a;
                cin >> a;
                if(i>n && j>n) S+=a;
                pf[i][j] = a + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
            }
        }
        for(ll f = 1;f<=n;f++){
            for(ll t = 1;t<=n;t++){
                ll x;
                //f - left/right, t - top/bottom
                x = min(sumrow(f, n+1, n+t), sumrow(f, n+t, n+n)) + min(sumcol(n+t, f+1, n), sumcol(n+t, 1, f-1))
                  + sum(n+1, n+n, 1, n) - max({sum(n+1, n+n-(n-f), 1, n-(n+n-t)), sum(n+1, n+n-(n-f), t-n, n),
                    sum(n+f, n+n, 1, n-(n+n-t)), sum(n+f, n+n, t-n, n)}); // F xbot n-f or xtop f-1, T xright n+n-t or xleft t-n-1
                v = min(v, x);
                //f - top/bot, t - left, right
                x = min(sumcol(f, n+1, n+t), sumcol(f, n+t, n+n)) + min(sumrow(n+t, f+1, n), sumrow(n+t, 1, f-1))
                  + sum(1, n, n+1, n+n) - max({sum(1, n-(n-t), n+f, n+n), sum(1, n-(n-t), n+1, n+f),
                    sum(t, n, n+f, n+n), sum(t, n, n+1, n+f)}); // F xleft f-1 xright n-f, T xbot n-t xtop t-1
                v = min(v, x);
            }
        }
        cout<<S+v<<'\n';
    }
}