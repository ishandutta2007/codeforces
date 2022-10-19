#include <iostream>
using namespace std;

typedef long long ll;

ll S, X;

ll solve() {
    S -= X;
    if (S < 0 || S % 2) return 0;
    S /= 2;
    if (S & X) return 0;
    ll sol = 1ll << __builtin_popcountll(X);
    if (!S) sol -= 2;
    return sol;
}

int main() {
    cin >> S >> X;
    cout << solve() << endl;
    return 0;
}