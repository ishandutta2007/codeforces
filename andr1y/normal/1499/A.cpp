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
        ll n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;
        if(k1>k2) swap(k1, k2);
        if(!(k1/2 + k2/2 >= w || (k1>0 && (k1-1)/2 + (k2-1)/2 + 1 >= w))) cout<<"no\n";
        else{
            k1=n-k1;
            k2=n-k2;
            swap(k1, k2);
            w=b;
            if(!(k1/2 + k2/2 >= w || (k1>0 && (k1-1)/2 + (k2-1)/2 + 1 >= w))) cout<<"no\n";
            else cout<<"yes\n";
        }
    }
}