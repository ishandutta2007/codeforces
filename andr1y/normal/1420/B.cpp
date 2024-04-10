#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll cnt[35];
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        ll res=0;
        for(ll a, i=0;i<n;i++){
            cin >> a;
            ll L = 0;
            for(;(1<<L)<=a;L++);
            res+=cnt[L]++;
        }
        cout<<res<<'\n';
    }
}