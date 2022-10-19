#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    for (cin >> ntest; ntest; ntest--) {
        long long p, q, b;
        cin >> p >> q >> b;
        long long GCD = __gcd(p, q);
        q /= GCD;
        while (1) {
            long long u = __gcd(q, b);
            if (u == 1) break;
            while (q % u == 0) q /= u;
        }
        if (q == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }
    return 0;
}