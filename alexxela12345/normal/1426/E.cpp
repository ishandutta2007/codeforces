#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

#define int long long

signed main() {
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    int a2, b2, c2;
    cin >> a2 >> b2 >>  c2;

    int ans2 = min(a, b2) + min(b, c2) + min(c, a2);

    int ans1 = 0;

    ans1 = 
        min(a, a2 + c2) +
        min(b, b2 + a2) +
        min(c, c2 + b2);
        

    cout << n - ans1  << " " << ans2 << endl;
}