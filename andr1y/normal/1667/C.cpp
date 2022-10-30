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
const ll N = 5e5+20;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    if(n==1){
        cout<<"1\n1 1\n";
    }else if(n==2){
        cout<<"1\n1 1\n";
    }else if(n==3){
        cout<<"2\n1 1\n1 2\n";
    }else if(n==4){
        cout<<"3\n1 2\n2 1\n4 4\n";
    }else{
        ll z = ((n-1)/3)*2 + 1;
        ll ev = (z+1)/2, od = z-ev;
        cout<<z+(n%3==0?1:0)<<'\n';
        for(ll i = 1;i<=ev;i++){
            cout<<i<<' '<<ev-i+1<<'\n';
        }
        for(ll i = 1;i<=od;i++){
            cout<<n-i+1<<' '<<n-(od-i+1)+1<<'\n';
        }
        if(n%3==0) cout<<ev+1<<' '<<ev+1<<'\n';
    }
}