#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        ll n;
        cin >> n;
        int ans = 0;
        while(n%5 == 0) {
            n/= 5;
            n *= 4;
            ans++;
        }
        while(n%3 == 0) {
            n /= 3;
            n *= 2;
            ans++;
        }
        while(n%2 ==0) {
            n /= 2;
            ans++;
        }
        if(n != 1)
            ans = -1;
        cout << ans << '\n';
    }
    return 0;
}