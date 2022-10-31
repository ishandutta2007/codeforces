// -- //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        yree aps, bps;
        ll del=0;
        ll n = s.length();
        for(ll i = n-1;i+1;i--){
            if(s[i]=='A'){
                if(bps.size()){
                    ll b = *bps.find_by_order(0);
                    if(!aps.order_of_key(b)){
                        del+=2;
                        bps.erase(b);
                    }else{
                        aps.insert(i);
                    }
                }else{
                    aps.insert(i);
                }
            }else if(s[i]=='B'){
                bps.insert(i);
            }
        }
        //cerr<<"a"<<aps.size();
        cout<<aps.size()+(bps.size()%2)<<'\n';
    }
}