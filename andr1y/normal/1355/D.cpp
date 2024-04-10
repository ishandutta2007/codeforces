//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll n, s;
    cin >> n >> s;
    ll u = s-n+1;
    if(u<=n) cout << "NO\n";
    else{
        cout << "YES\n";
        cout << u << ' ';
        for(ll i = 1;i<n;i++) cout << "1 ";
        cout << "\n"<<n<<"\n";
    }
}