#include <bits/stdc++.h>

using namespace std;

#define INF 1000000100
#define M 100100

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int bin(long long x, long long a, long long mod) {
    long long y = 1;
    while (a) {
        if (a & 1)
            y = (y * x) % mod;
        x = (x * x) % mod;
        a >>= 1;
    }
    return y;
}

int primitiveRoot(int p) {
    vector<int> d;
    int t = p - 1;
    for (int i = 2; i <= t; ++i)
        if (t % i == 0) {
            d.push_back(i);
            while (t % i == 0)
                t /= i;
        }

    for (int i = 1; ; ++i) {
        bool good = true;
        for (int x : d)
            if (bin(i, (p - 1) / x, p) == 1) {
                good = false;
                break;
            }
        if (good)
            return i;
    }
}

int main() {
    int p;
    cin >> p;
    if (p == 1) {
        cout << "YES\n";
        cout << "1\n";
        return 0;
    }

    if (p == 4) {
        cout << "YES\n";
        cout << "1\n3\n2\n4\n";
        return 0;
    }

    if (!isPrime(p)) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    int root = primitiveRoot(p);

    for (int i = 0; i < p - 1; ++i)
        if (i % 2 == 0)
            cout << bin(root, p - 1 - i, p) << "\n";
        else
            cout << bin(root, i, p) << "\n";
    cout << p << "\n";

    return 0;
}