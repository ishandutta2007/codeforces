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
        vector<int> b;
        multiset<int> store;
        for (int i = 0; i < n; i++) store.insert(a[i]);
        int run;
        for (int i = 0; i < n; i++) {
            int x;
            if (i == 0) {
                x = *store.rbegin();
                run = x;
            } else {
                int best = *store.begin();
                for (int y: store) {
                    if (__gcd(y, run) > __gcd(best, run)) {
                        best = y;
                    }
                }
                x = best;
                run = __gcd(run, x);
            }
            store.erase(store.find(x));
            b.push_back(x);
        }
        for (int i = 0; i < n; i++) cout << b[i] << " ";
        cout << '\n';
    }
    return 0;
}