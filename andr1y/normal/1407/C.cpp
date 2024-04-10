// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 14880;
ll res[N];
ll cnt[N];
signed main(){
    ll n;
    cin >> n;
    if(n==1){
        cout<<"! 1"<<endl;
        cout.flush();
    }else{
        ll np = 1;
        for(ll i = 2;i<=n;i++){
            cout<<"? "<<i<<" "<<np<<endl;
            cout.flush();
            ll rpi, rip;
            cin >> rip;
            cout<<"? "<<np<<" "<<i<<endl;
            cout.flush();
            cin >> rpi;
            if(rip>rpi){
                res[i]=rip;
            }else{
                res[np]=rpi;
                np=i;
            }
        }
        for(ll i = 1;i<=n;i++) cnt[res[i]]++;
        for(ll i = 1;i<=n;i++){
            if(!cnt[i]) res[np]=i;
        }
        /*for(ll i = 1;i<=n;i++){
            if(i==np) continue;
            cout<<"? "<<i<<" "<<np<<endl;
            cout.flush();
            ll r;
            cin >> r;
            res[i]=r;
        }*/
        cout<<"! ";
        for(ll i = 1;i<=n;i++) cout<<res[i]<<" ";
        cout<<endl;
        cout.flush();
    }
}