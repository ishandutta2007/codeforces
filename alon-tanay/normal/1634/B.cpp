#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t --) {
        ll n, x, y;
        cin >> n >> x >> y;
        bool odd = (x&1)^(y&1);

        for(int i = 0; i < n; i ++) {
            cin >> x;
            odd ^= (x&1);
        }
        cout << (odd ? "Bob" : "Alice") << "\n";
    }
    return 0;
}