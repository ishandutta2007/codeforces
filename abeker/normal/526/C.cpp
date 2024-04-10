#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

ll A, B, C, D, E;

pii ext(pii p) {
    if (!p.second) return pii(1, 0);
    pii tmp = ext(pii(p.second, p.first % p.second));
    return pii(tmp.second, tmp.first - p.first / p.second * tmp.second);
}

void load() {
    cin >> C >> D >> E >> A >> B;
}

ll solve() {
    if (B * D < A * E) {
        swap(A, B);
        swap(D, E);
    }
    ll G = __gcd(A, B);
    A /= G;
    B /= G;
    C /= G;
    ll sol = 0;
    if (A * A < C) {
        pii coef = ext(pii(A, B));
        for (ll i = 0; i < A && i < C; i++) {
            ll y = (coef.second * (C - i) % A + A) % A;
            ll x = (C - i - B * y) / A;
            if (x >= 0) sol = max(sol, D * x + E * y);
        } 
    }
    else 
        for (ll x = 0; A * x <= C; x++)
            sol = max(sol, D * x + (C - A * x) / B * E);
    return sol;
}

int main() {
    ios::sync_with_stdio(0);
    load();
    cout << solve() << endl;
    return 0;
}