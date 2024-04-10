// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        do{
            ll sn=n, sm=0;
            while(sn) sm+=(sn%10), sn/=10;
            ll e = __gcd(n, sm);
            if(e>1){
                cout<<n<<'\n';
                break;
            }else n++;
        }while(true);
    }
}