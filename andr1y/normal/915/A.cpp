#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define SPEED ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ld long double
int main(){
    SPEED;
    ll n, k, l=LLONG_MAX;
    cin >> n >> k;
    for(ll i=0;i<n;i++){
        ll t, r=0;
        cin >> t;
        for(r=0;r<k;r+=t)t=t;
        if(r==k)l=min(k/t, l);
    }
    cout << l;
}