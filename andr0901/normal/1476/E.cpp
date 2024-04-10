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

constexpr int TEMPLATES = 1e6;

int convert(string& s) {
    int ans = 0;
    for (char c : s) {
        ans *= 27;
        if (c == '_')
            ans += 26;
        else
            ans += c - 'a';
    }
    return ans;
}

vector<vector<int>> gr;
vector<int> used;
vector<int> ord;

void dfs(int v) {
    used[v] = 1;
    for (int u : gr[v]) {
        if (used[u] == 1) {
            cout << "NO\n";
            exit(0);
        }
        if (!used[u]) {
            dfs(u);
        }
    }
    used[v] = 2;
    ord.pb(v + 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> get(TEMPLATES, -1);
    vector<string> t(n);
    forn (i, 0, n) {
        cin >> t[i];
        get[convert(t[i])] = i;
    }
    gr.resize(n);
    forn (i, 0, m) {
        string s;
        int idx;
        cin >> s >> idx, --idx;
        bool self = false;
        forn (mask, 0, 1 << k) {
            string cur = s;
            forn (j, 0, k) {
                if ((mask >> j) & 1) {
                    cur[j] = '_';
                }
            }
            int to = convert(cur);
            if (get[to] == idx) {
                self = true;
            }
            if (get[to] != -1 && get[to] != idx) {
                gr[idx].pb(get[to]);
                cerr << idx << " " << get[to] << "\n";
            }
        }
        if (!self) {
            cout << "NO\n";
            return 0;
        }
        cerr << "--\n";
    }
    used = vector<int> (n);
    forn (i, 0, n) {
        if (!used[i]) {
            dfs(i);
        }
    }
    cout << "YES\n";
    reverse(all(ord));
    cout << ord << "\n";
    return 0;
}