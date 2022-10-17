#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) {
    return cout << "(" << p.first << ", " << p.second << ")";
}
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "{"; for (int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "}";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        map<int, int> cnt;
        for (int i = 0; i <= n; i++) cnt[i] = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int one = 0;
        bool b1 = true;
        int two = 0;
        bool b2 = true;
        for (int i = 0; i <= n; i++) {
            if (cnt[i] >= 2 && b2) two++;
            else b2 = false;
            if (cnt[i] >= 1 && b1) one++;
            else b1 = false;
        }
        cout << one + two << '\n';
    }
    return 0;
}