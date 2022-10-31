#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll w, h, u1, d1, u2, d2;
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
    for(ll i = h;i>0;i--){
        w+=i;
        if(i == d1) w = max<ll>(0, w-u1);
        if(i == d2) w = max<ll>(0, w-u2);
    }
    cout << w;
}