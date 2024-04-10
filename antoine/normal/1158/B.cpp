#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    const int x = (n - k) / 2;
    for (int i = 0; i < n; ++i)
        cout << (i % (x + 1) == x);
    return 0;
}