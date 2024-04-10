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
        ll n, m;
        cin >> n >> m;
        if(n==1||m==1){cout << "YES\n";continue;}
        if(n==2&&m==2){cout << "YES\n";continue;}
        cout << "NO\n";
    }
}