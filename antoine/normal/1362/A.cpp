#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;
typedef vector<int> vi;
typedef pair<int, int> pii;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }

        int ans = 0;
        for (int x : {8, 4, 2})
            while (b % x  == 0 && b / x >= a) {
                b /= x;
                ans++;
            }

        cout << (a == b ? ans : -1) << '\n';
    }

    return 0;
}