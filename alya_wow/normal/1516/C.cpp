#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
#ifdef BZ
    freopen("../a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    int g = 0;
    for (int &i : a) {
        cin >> i;
        s += i;
        g = gcd(g, i);
    }
    for (int &i : a)
        i /= g;
    s /= g;
    const int N = 2e5 + 10;
    bitset<N> q;
    q[0] = 1;
    for (int i : a)
        q |= q << i;
    if (s % 2 == 0 && q[s / 2]) {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++)
            if (a[i] % 2 == 1) {
                cout << i + 1;
                return 0;
            }
    } else {
        cout << 0;
    }
}