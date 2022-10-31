//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 32;
uint64_t sk[N];
ll a[N], n, k;
bool ok(ll i){
    sk[i] = 0;
    ll pp = 0;
    bool o2 =1;
    while(a[i]){
        ll v = a[i]%k;
        if(v > 1) {
            o2 = 0;
            break;
        }
        if(v) sk[i]|=(1LL<<pp);
        pp++;
        a[i]/=k;
    }
    return o2;
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        cin >> n >> k;
        bool o2 = 1;
        for(ll i =0;i<n;i++){
            cin >> a[i];
            o2 &= ok(i);
        }
        if(!o2) {
            cout << "NO\n";
            continue;
        }
        ll ak =0;
        for(ll i = 0;i<n&&o2;i++){
            if(ak&sk[i]) o2=0;
            else ak|=sk[i];
        }
        if(o2)cout<<"YES\n";
        else cout <<"NO\n";
    }
}