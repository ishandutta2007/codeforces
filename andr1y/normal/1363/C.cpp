//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1228;
ll st[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, x;
        cin >> n >> x;
        for(ll i = 1;i<=n;i++) st[i]=0;
        for(ll a, b, i = 1;i<n;i++){
            cin >> a >> b;
            ++st[a], st[b]++;
        }
        if(st[x]<=1||(n&1)==0) cout<<"Ayush\n";
        else cout << "Ashish\n";
    }
}