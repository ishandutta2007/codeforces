#include <bits/stdc++.h>

using namespace std;

const int C = 7e5;

int n, x, xr;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> x;
    if(n == 2 && x == 0) return cout << "NO", 0;
    if(n == 1) return cout << "YES\n" << x, 0;
    if(n == 2) return cout << "YES\n" << "0 " << x, 0;
    cout << "YES\n";
    for(int i = 0; i < n - 3; i++) cout << i << ' ', xr ^= i;
    xr ^= (n - 3);
    if((xr ^ x) == 0) xr ^= (n - 3) ^ (n - 2), cout << n - 2 << ' ';
    else cout << n - 3 << ' ';
    cout << C << ' ' << (C ^ xr ^ x);
}