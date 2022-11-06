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


        ll n;
        cin >> n;

        ll res = 0;
        while (n) {
            res += n;
            n >>= 1;
        }
        cout << res << '\n';
    }
    return 0;
}