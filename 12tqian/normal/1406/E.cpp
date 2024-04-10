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
    int n; cin >> n;
    int rem = n;
    vector<bool> in(n, true);
    int total = 0;
    int cnt = n;
    vector<bool> ideal(n + 1, true);
    auto ask = [&](int t, int a) -> int {
        cout << (char) ('A' + t) << " " << a << endl;
        for (int i = a; i <= n; i += a) {
            ideal[i] = false;
        }
        int x; cin >> x;
        return x;
    };
    vector<int> spf(n + 1);
    spf[1] = 1;
    for (int i = 1; i <= n; i++) {
        spf[i] = i;
    }
    for (int i = 4; i <= n; i += 2) {
        spf[i] = 2;
    }
    for (int i = 3; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    vector<int> pri;
    for (int i = 2; i <= n; i++) {
        if (spf[i] == i) {
            pri.push_back(i);
        }
    }
    int cut = sqrt(n);
    int ans = 1;
    auto bash_prime = [&](int p) -> bool {
        ll base = p;
        bool ok = false;
        while (ans % p == 0) ans /= p;
        while (base <= n && ask(0, base)) {
            base *= p;
            ok = true;
        }
        ans *= base / p;
        return ok;
    };
    for (int p: pri) {
        if (p > cut) break;
        ask(1, p);
        bash_prime(p);
    }
    int hi = pri.size() - 1;
    int lo = 0;
    int times = 0;
    for (int p: pri) {
        if (p > cut) {
            lo = times;
            break;
        }
        times++;
    }
    int num = ask(0, 1);
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        int cur = num;
        for (int i = lo; i <= mid; i++) {
            cur -= ask(1, pri[i]);
        }
        num = ask(0, 1);
        if (cur != num) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (lo >= 0 && lo < pri.size()) {
        ask(1, pri[lo]);
        bash_prime(pri[lo]);
    }
    if (hi >= 0 && hi < pri.size()) {
        ask(1, pri[hi]);
        bash_prime(pri[hi]);
    }
    ask(2, ans);
    cout << ans << '\n';
    return 0;
}