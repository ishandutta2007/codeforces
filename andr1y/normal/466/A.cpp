// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    if(m*a<b){
        cout<<a*n;
    }else cout<<(n/m)*b+min((n%m)*a, b);
}