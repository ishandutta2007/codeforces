//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, s0=0, s1=0, x;
        cin >> n>>x;
        for(ll a, i=0;i<n;i++){
            cin >> a;
            if(a&1) s1++;
            else ++s0;
        }
        if(s1==0){
            cout<<"No\n";
        }else{
            --s1;
            --x;
            s1-=s1%2;
            if(s0+s1>=x&&(x%2==0||(x%2==1&&s0>0))) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}