#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int f(int n) {
    if(n <= 3)
        return n - 1;
    return 2 + n%2;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << f(n) << '\n';
    }
    return 0;
}