//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll mv= 0;
    mv=max(mv, a+b+c);
    mv=max(mv, a*b*c);
    mv=max(mv, a+b*c);
    mv=max(mv, a*b+c);
    mv=max(mv, a*(b+c));
    mv=max(mv, (a+b)*c);
    cout << mv << '\n';
}