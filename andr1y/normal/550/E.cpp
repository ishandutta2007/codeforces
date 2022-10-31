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
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 1e5+228;

ll a[N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }
    ll x = n-1, t = 0;
    while(x>=0 && !a[x]) --x, ++t;
    if(t==0){
        cout<<"NO\n";
        return 0;
    }
    if(t&1){
        cout<<"YES\n";
        cout<<a[0];
        for(ll i = 1;i<n;i++){
            cout<<"->"<<a[i];
        }
    }else{
        if(t>2){
            cout<<"YES\n";
            cout<<a[0];
            for(ll i = 1;i<n;i++){
                cout<<"->";
                if(i==n-3) cout<<'(';
                cout<<a[i];
                if(i==n-2) cout<<')';
            }
            return 0;
        }
        ll y = x;
        while(y>=0 && a[y]) --y;
        if(y<0){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            if(y == 0) cout<<'(';
            cout<<a[0];
            for(ll i = 1;i<n;i++){
                cout<<"->";
                if(i==y || i==y+1) cout<<'(';
                cout<<a[i];
                if(i==n-2) cout<<"))";
            }
        }
    }
}