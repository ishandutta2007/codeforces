//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

#define int long long

const string haha = "haha";

class Node {
public:
    Node(const string& s = "") {
        if (s.size() <= 4) {
            st = s;
            fn = "";
            cnt = 0;
        } else {
            st = fn = "";
            forn (i, 0, 4) {
                st += s[i];
            }
            cnt = 0;
            forn (i, 1, s.size() - 4) {
                cerr << s << " " << s.substr(i, 4) << "\n";
                cnt += (s.substr(i, 4) == haha);
            }
            forn (i, s.size() - 4, s.size()) {
                fn += s[i];
            }
        }
        if (s.size() <= 8) {
            val = s;
            cnt = 0;
            forn (i, 1, (int)s.size() - 4) {
                cnt += s.substr(i, 4) == haha;
            }
        }
    }

    Node operator+(const Node& other) const {
        if (!val.empty() && !other.val.empty()) {
            return val + other.val;
        }

        Node ans;
        ans.st = st;
        ans.fn = other.fn;
        ans.cnt = cnt + other.cnt;
        string conc = fn + other.st;
        forn (i, 0, conc.size()) {
            ans.cnt += conc.substr(i, 4) == haha;
        }
        return ans;
    }

    string get_st() const {
        return st;
    }

    string get_fn() const {
        return fn;
    }

    int get_cnt() const {
        return cnt;
    }

    string get_val() const {
        return val;
    }

private:
    string st, fn;
    int cnt;
    string val;
};

void solve() {
    int q;
    cin >> q;
    map<string, Node> mp;
    string lst;
    while (q --> 0) {
        string var, op;
        cin >> var >> op;
        if (op == ":=") {
            string val;
            cin >> val;
            mp[var] = val;
        } else {
            string l, r;
            cin >> l >> r >> r;
            auto node = mp[l] + mp[r];
            mp[var] = node;
        }
        lst = var;
        cerr << lst << ":" << mp[lst].get_st() << "|" << mp[lst].get_fn() << "|" << mp[lst].get_val() << "|" << mp[lst].get_cnt()  << "\n";
    }
    auto node = mp[lst];
    cout << 
        node.get_cnt() +
        (node.get_st() == haha) +
        (node.get_fn() == haha)
        << "\n";

}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}