#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
    int n, m, a;
    cin >> n >> m >> a;
    int na = n / a;
    int ma = m / a;
    if(n % a != 0) {
        na++;
    }
    if(m % a != 0) {
        ma++;
    }
    cout << na * ma;
}