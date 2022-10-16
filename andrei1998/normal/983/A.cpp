#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

lint prod(const lint a, lint b, const lint MOD) {
    lint ans = 0;
    lint aux = a;
    while (b) {
        if (b & 1) {
            ans += aux;
            if (ans >= MOD)
                ans -= MOD;
        }
        aux += aux;
        if (aux >= MOD)
            aux -= MOD;
        b >>= 1;
    }

    return ans;
}

lint expo(const lint a, lint b, const lint MOD) {
    lint ans = 1;
    lint aux = a;
    while (b) {
        if (b & 1)
            ans = prod(ans, aux, MOD);
        aux = prod(aux, aux, MOD);
        b >>= 1;
    }
    return ans;
}

lint gcd(lint a, lint b) {
    if (!b)
        return a;
    lint r = a % b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    while (n --) {
        lint p, q, b;
        cin >> p >> q >> b;

        lint g = gcd(p, q);
        p /= g;
        q /= g;

        lint put = expo(b % q, 64, q);
        if (put == 0)
            cout << "Finite\n";
        else
            cout << "Infinite\n";
    }

    return 0;
}