//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N = 5228;
ll pf[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    for(ll i = 0;i<n;i++){
        cin >> pf[i];
        if(i) pf[i]+=pf[i-1];
    }
    ld sk = 0;
    for(ll i = k-1;i<n;i++){
        for(ll j = i-k+1;j>=0;j--){
            ld s = pf[i]-(j?pf[j-1]:0);
            sk = max(sk, s/(i-j+1));
        }
    }
    cout << fixed << setprecision(10);
    cout << sk << '\n';
}