// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;

signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        if(__builtin_popcountll(n)==1){
            if(n!=2) cout<<"FastestFinger\n";
            else cout<<"Ashishgup\n";
        }else{
            if(n&1){
                cout<<"Ashishgup\n";
            }else{
                if((n/2)%2==1){
                    n/=2;
                    ll c=1;
                    for(ll i = 2;i*i<=n;i++){
                        if(n%i==0){
                            c=2;
                            break;
                        }
                    }
                    if(c==1) cout<<"FastestFinger\n";
                    else cout<<"Ashishgup\n";
                }else{
                    cout<<"Ashishgup\n";
                }
            }
        }
    }
}