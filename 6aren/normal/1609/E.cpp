#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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


const int INF = 1e9 + 7;
const int N = 100005;

int n, q;

class SegmentTreeMin {
  public: 
    int n;
    vector<int> a, it, lazy;
    int dump_val;

    #define mid ((l + r) / 2)
    #define left (2 * k)
    #define right (2 * k + 1)

    void build(int k, int l, int r) {
        if (l == r) {
            it[k] = a[l];
            return;
        }
        build(left, l, mid);
        build(right, mid + 1, r);
        it[k] = min(it[left], it[right]);
    }

    SegmentTreeMin(const vector<int>& a) : a(a), dump_val(INF) {
        n = static_cast<int>(a.size());
        it.resize(4 * (n + 1));
        lazy.resize(4 * (n + 1));
        build(1, 0, n - 1);
    }

    void down(int k) {
        int val = lazy[k];
        if (val == 0) return;
        lazy[k] = 0;
        it[left] += val;
        it[right] += val;
        lazy[left] += val;
        lazy[right] += val;
    }

    void _update(int k, int l, int r, int u, int v, int val) {
        if (l > v || r < u) return;
        if (l >= u && r <= v) {
            it[k] += val;
            lazy[k] += val;
            return;
        } 
        down(k);
        _update(left, l, mid, u, v, val);
        _update(right, mid + 1, r, u, v, val);
        it[k] = min(it[left], it[right]);
    }

    void update(int u, int v, int val) {
        _update(1, 0, n - 1, u, v, val);
    }

    int _get(int k, int l, int r, int u, int v) {
        if (l > v || r < u) return dump_val;
        if (l >= u && r <= v) return it[k];
        down(k);
        return min(_get(left, l, mid, u, v), _get(right, mid + 1, r, u, v));
    }

    int get(int l, int r) {
        return _get(1, 0, n - 1, l, r);
    }

    #undef mid
    #undef left
    #undef right
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> pref(n + 2);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        if (s[i] == 'a') pref[i]++;
        else if (s[i] == 'b') pref[i]--; 
    }

    vector<int> suff(n + 2);
    for (int i = n; i >= 1; i--) {
        suff[i] = (i == n ? 0 : suff[i + 1]);
        if (s[i] == 'c') suff[i]++;
        else if (s[i] == 'b') suff[i]--;
    }

    SegmentTreeMin it_pref(pref);
    SegmentTreeMin it_suff(suff);
    vector<int> sum(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        sum[i] = it_pref.get(0, i - 1) + it_suff.get(i, n + 1);
    }
    SegmentTreeMin it_sum(sum);

    int cnt_b = 0;
    for (int i = 1; i <= n; i++) cnt_b += (s[i] == 'b');

    auto val_pref = [](char ch) {
        return (ch == 'a' ? 1 : (ch == 'b' ? -1 : 0));
    };

    auto val_suff = [](char ch) {
        return (ch == 'c' ? 1 : (ch == 'b' ? -1 : 0));
    };

    while (q--) {
        int pos;
        char ch;
        cin >> pos >> ch;
        cnt_b += (ch == 'b') - (s[pos] == 'b');
        // for pref
        int delta = val_pref(ch) - val_pref(s[pos]);
        if (delta > 0) {
            for (int i = 0; i < delta; i++) {
                int cur = it_pref.get(0, pos - 1);
                int l = 1, r = n;
                int u = -1;
                while (r >= l) {
                    int mid = (l + r) / 2;
                    if (it_pref.get(0, mid) < cur) {
                        u = mid;
                        r = mid - 1;
                    } else l = mid + 1;
                }
                if (u != -1) it_sum.update(u + 1, n + 1, 1);
                it_pref.update(pos, n, 1);
            }
        }
        if (delta < 0) {
            for (int i = 0; i < abs(delta); i++) {
                int cur = it_pref.get(0, pos - 1);
                it_pref.update(pos, n, -1);
                int l = 1, r = n;
                int u = -1;
                while (r >= l) {
                    int mid = (l + r) / 2;
                    if (it_pref.get(0, mid) < cur) {
                        u = mid;
                        r = mid - 1;
                    } else l = mid + 1;
                }
                if (u != -1) it_sum.update(u + 1, n + 1, - 1);
            } 
        }
        // for suff
        delta = val_suff(ch) - val_suff(s[pos]);
        if (delta > 0) {
            for (int i = 0; i < delta; i++) {
                int cur = it_suff.get(pos + 1, n + 1);
                int l = 1, r = n;
                int u = -1;
                while (r >= l) {
                    int mid = (l + r) / 2;
                    if (it_suff.get(mid, n + 1) < cur) {
                        u = mid;
                        l = mid + 1;
                    } else r = mid - 1;
                }
                if (u != -1) it_sum.update(1, u, 1);
                it_suff.update(1, pos, 1);
            }
        }
        if (delta < 0) {
            for (int i = 0; i < abs(delta); i++) {
                int cur = it_suff.get(pos + 1, n + 1);
                it_suff.update(1, pos, -1);
                int l = 1, r = n;
                int u = -1;
                while (r >= l) {
                    int mid = (l + r) / 2;
                    if (it_suff.get(mid, n + 1) < cur) {
                        u = mid;
                        l = mid + 1;
                    } else r = mid - 1;
                }
                if (u != -1) it_sum.update(1, u, -1);
            } 
        }
        cout << it_sum.get(1, n + 1) + cnt_b << '\n';
        s[pos] = ch;
    }
    
    return 0;
}