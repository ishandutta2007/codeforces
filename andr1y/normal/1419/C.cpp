// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, x;
        cin >> n >> x;
        ll hx=0, sum=0;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            sum+=a[i];
            if(a[i]==x) hx++;
        }
        if(hx==n){
            cout<<"0\n";
        }else if(hx>=1||((sum/n)==x&&(sum%n)==0)){
            cout<<"1\n";
        }else cout<<"2\n";
    }
}