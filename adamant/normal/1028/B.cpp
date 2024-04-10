#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x),end(x)

const int maxn = 2e5 + 42;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int sum = 0;
    string a = "";
    string b = "";
    int suma = 0, sumb = 0;
    while(suma < n || sumb < n) {
        suma += 5;
        sumb += 13;
        a += "50";
        b += "49";
    }
    a += "50";
    b += "50";
    cout << a << endl;
    cout << b << endl;
    return 0;
}