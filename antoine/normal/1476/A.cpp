#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;

        ll s = (n / k) * k;
        if (s < n)
            s += k;
        cout << (s + n - 1) / n << '\n';
    }
    return 0;
}