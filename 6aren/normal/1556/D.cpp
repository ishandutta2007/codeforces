#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename A> ostream& operator<<(ostream &os, const vector<A> &vt) {
    os << '[';
    for (size_t i = 0; i + 1 < vt.size(); i++) os << vt[i] << ", ";
    if (!vt.empty()) os << vt.back();
    return os << ']';
}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef GAREN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define bit(x, y) ((x >> y) & 1)

void run_case() {
    int n, k;
    cin >> n >> k;
    vector<int> qa(n + 1);
    vector<int> qo(n + 1);
    // vector<int> a = {0, 1, 6, 4, 2, 3, 5, 4};
    for (int i = 2; i <= n; i++) {
        cout << "and " << 1 << ' ' << i << endl;
        cin >> qa[i];
        // qa[i] = a[1] & a[i];
        cout << "or " << 1 << ' ' << i << endl;
        cin >> qo[i];
        // qo[i] = a[1] | a[i];
    }
    int qa23;
    cout << "and " << 2 << ' ' << 3 << endl;
    cin >> qa23;
    // qa23 = (a[2] & a[3]);
    
    vector<int> res(n + 1);
    for (int i = 30; i >= 0; i--) {
        bool check_or = true;
        for (int j = 2; j <= n; j++) {
            if (bit(qo[j], i) == 0) check_or = false;
        }
        bool check_and = true;
        for (int j = 2; j <= n; j++) {
            if (bit(qa[j], i) == 1) check_and = false;
        }
        assert(check_or || check_and);
        dbg(check_or, check_and);
        if (check_or && check_and) {
            if (bit(qa23, i)) {
                for (int j = 2; j <= n; j++) {
                    res[j] += (1 << i);
                }
            } else {
                res[1] += (1 << i); 
            }
        } else if (check_or) {
            res[1] += (1 << i);
            for (int j = 2; j <= n; j++) {
                if (bit(qa[j], i)) res[j] += (1 << i);
            }
        } else {
            for (int j = 2; j <= n; j++) {
                if (bit(qo[j], i)) res[j] += (1 << i);
            }
        }
    }
    sort(res.begin() + 1, res.begin() + n + 1);
    // dbg(res);
    cout << "finish " << res[k] << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    while (tests--) run_case();
    return 0;
}