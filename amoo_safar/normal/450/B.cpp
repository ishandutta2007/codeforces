#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int main(){
    ll x,y;
    cin >> x >> y;
    ll k;
    cin >> k;
    k%=6;
    if(k==0) k =6;
    x+=MOD;
    y+=MOD;
    x%=MOD;
    y%=MOD;
    if(k==1){
        cout << x%MOD ;
        return 0;
    }
    if(k==2){
        cout << y%MOD ;
        return 0;
    }
    ll b;
    for(int i = 2;i<k;i++){
        b = y;
        y = (y-x+MOD)%MOD;
        x = (b+MOD) % MOD;

    }
    cout << y%MOD;
    return 0;
}