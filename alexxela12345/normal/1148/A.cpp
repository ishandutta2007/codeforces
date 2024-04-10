#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int kek = 2 * min(a, b);
    if (a != b) {
        kek += 1;
    }
    cout << kek + 2 * c << endl;
}