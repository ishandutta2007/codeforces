#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) {
    return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "{"; for (int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "}"; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int zero = 0;
        for (int i = 0; i < n; i++) {
            zero += (a[i] == 0);
        }
        int one = n - zero;
        if (zero >= n / 2) {
            cout << zero << '\n';
            for (int i = 0; i < zero; i++) cout << 0 << " ";
            cout << '\n';
        } else {
            int num = one / 2 * 2;
            cout << num << '\n';
            for (int i = 0; i < num; i++) cout << 1 << " ";
            cout << '\n';
        }
    }
    return 0;
}