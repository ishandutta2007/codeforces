#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

string f() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a)
        cin >> x;
    adjacent_difference(a.begin(), a.end(), a.begin());
    ll sum = 0;
    for(int x : a)
        sum += max(0, -x);
    return sum <= a[0] ? "YES" : "NO";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >> t;
    while(t--) {
        auto res = f();
        cout << res << '\n';
    }
    return 0;
}