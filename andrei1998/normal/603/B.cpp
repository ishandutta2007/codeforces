#include <iostream>

using namespace std;

const int mod = 1000000007;

int put (int a, int b) {
    if (!b)
        return 1;
    else if (b & 1)
        return (1ll * a * put(a, b - 1)) % mod;
    else {
        int aux = put(a, b >> 1);
        return (1ll * aux * aux) % mod;
    }
}

const int NMAX = 1000005;
int vis[NMAX];

int p, k;

void parc (int node) {
    while (!vis[node]) {
        vis[node] = true;
        node = (1ll * k * node) % p;
    }
}

int main()
{
    cin >> p >> k;

    if (k == 0) {
        cout << put(p, p - 1) << '\n';
        return 0;
    }

    if (k == 1) {
        cout << put(p, p) << '\n';
        return 0;
    }

    int l = 0;
    for (int i = 0; i < p; ++ i)
        if (!vis[i]) {
            parc(i);
            ++ l;
        }

    cout << put(p, l - 1) << '\n';
    return 0;
}