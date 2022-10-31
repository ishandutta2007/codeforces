#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q,n;
    cin >> q;
    while(q--){
        cin >> n;
        ll e = LLONG_MAX, o=1, k=0;
        for(ll a, i=0;i<n;i++){
            cin >> a;
            if(a>=e) o=0;
            e=a;
        }
        if(o) cout<<"NO\n";
        else cout<<"YES\n";
    }
}