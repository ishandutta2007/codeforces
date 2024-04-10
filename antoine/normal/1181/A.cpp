#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ll x,y,z;
    cin >>x >>y>>z;

    ll a = x/z + y/z;
    ll b=  0;

    x %= z, y %= z;
    if(x + y >= z) {
   a++;
   b = min(z-x, z-y);
    }
    cout << a << ' ' << b;
    return 0;
}