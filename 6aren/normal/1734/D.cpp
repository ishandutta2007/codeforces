#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        k--;
        vector<int> a(n);
        for (int &e : a) {
            cin >> e;
        }

        int p, q;
        p = q = k;

        long long cur = a[k];

        // auto justGo = [&](auto start, auto end, long long &curSum) {
        //     long long goingSum = curSum;
        //     for (auto it = start; it != end; it = it + 1) {
        //         goingSum += *it;
        //         if (goingSum < 0) {
        //             return make_pair(false, it - 1);
        //         }
        //         if (goingSum >= curSum) {
        //             curSum = goingSum;
        //         }
        //     }
        // };

        auto findToRight = [&](int u) {
            long long mn = 0, sum = 0;
            for (int i = u + 1; i < n; i++) {
                sum += a[i];
                if (sum > 0) return make_pair(i, -mn);
                mn = min(mn, sum);
            }
            return make_pair(-1, -mn);
        };

        auto findToLeft = [&](int u) {
            long long mn = 0, sum = 0;
            for (int i = u - 1; i >= 0; i--) {
                sum += a[i];
                if (sum > 0) return make_pair(i, -mn);
                mn = min(mn, sum);
            }
            return make_pair(-1, -mn);
        };
        
        int posToRight = k, posToLeft = k;
        long long needToRight = 0, needToLeft = 0;

        while (p != 0 && q != n - 1) {
            if (cur >= needToRight && posToRight != -1) {
                // move to right
                for (int i = q + 1; i <= posToRight; i++) {
                    cur += a[i];
                }
                q = posToRight;
                // find new right
                auto foo = findToRight(q);
                posToRight = foo.first;
                needToRight = foo.second;
                continue;
            }
            if (cur >= needToLeft && posToLeft != -1) {
                // move to left
                for (int i = p - 1; i >= posToLeft; i--) {
                    cur += a[i];
                }
                p = posToLeft;
                // find new left
                auto foo = findToLeft(p);
                posToLeft = foo.first;
                needToLeft = foo.second;
                continue;
            }
            break;
        }
        cout << (cur >= min(needToLeft, needToRight) ? "YES\n" : "NO\n");
    }
    return 0;
}