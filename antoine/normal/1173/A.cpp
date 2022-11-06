#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

char f(int x) {
    return x > 0 ? '+' : x ? '-' : '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int x, y, z;
    cin >> x >> y >> z;

    cout << (f(x - y + z) != f(x - y - z) ? '?' : f(x - y));
    return 0;
}