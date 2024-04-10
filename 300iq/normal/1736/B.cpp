#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
#include <map>

#define x _x
#define y _y

using namespace std;

mt19937 rnd(228);

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector <int> b(n + 1);
        auto gcd = [&] (int a, int b) {
            while (true) {
                if (a > b) swap(a, b);
                if (a == 0) return b;
                b %= a;
            }
        };
        auto lcm = [&] (int a, int b) {
            if (a == 0 || b == 0) return max(a, b);
            return a * b / gcd(a, b);
        };
        for (int i = 0; i < n; i++) {
            b[i] = lcm(b[i], a[i]);
            b[i + 1] = lcm(b[i + 1], a[i]);
        }
        bool bad = false;
        for (int i = 0; i < n; i++) {
            if (gcd(b[i], b[i + 1]) != a[i]) bad = true;
        }
        if (bad) cout << "NO\n";
        else cout << "YES\n";
    }
}