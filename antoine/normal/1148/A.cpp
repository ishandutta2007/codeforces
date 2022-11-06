#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;
    a = min(a, b + 1);
    b = min(b, a + 1);
    cout << a + b + 2*c;

    return 0;
}