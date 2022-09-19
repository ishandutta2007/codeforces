#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 100001;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    ll x = 0;
    ll y = 0;
    ll z = 0;
    ll a, b, c;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }
    if((x == 0) and (y == 0) and (z == 0)) cout << "YES";
    else cout << "NO";
    return 0;
}