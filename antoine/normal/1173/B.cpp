#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    cout << 1 + n / 2 << '\n';

    int r = 1, c = 1;
    while (n--) {
        cout << r << ' ' << c << '\n';
        (n & 1 ? r : c)++;
    }
    return 0;
}