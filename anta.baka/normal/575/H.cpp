#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull P = 1000000007;

ull pm(ull n, ull p) {
    if(p == 1) return n;
    if(p % 2 == 0) return ((n=pm(n, p/2))*n) % P;
    return (pm(n, p-1) * n) % P;
}

int main()
{
    int n;
    cin >> n;
    ull a = 1, b = 1;
    for(int w=1; w<=n+1; w++) {
        a = (a * (w + n + 1)) % P;
        b = (b * w) % P;
    }
    cout << (pm(b, P-2) * a - 1) % P;
    return 0;
}