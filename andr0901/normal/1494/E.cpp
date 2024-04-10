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

vector<map<int, char>> gr;

int cnt_odd = 0, cnt_even = 0;

void sub(int v, int u) {
    if (gr[v][u] && gr[u][v]) {
        --cnt_odd;
        if (gr[v][u] == gr[u][v]) {
            --cnt_even;
        }
    }
}

void add(int v, int u) {
    if (gr[v][u] && gr[u][v]) {
        ++cnt_odd;
        if (gr[v][u] == gr[u][v]) {
            ++cnt_even;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    gr.resize(n);
    while (q --> 0) {
        char tp;
        cin >> tp;
        if (tp == '+') {
            int v, u;
            cin >> v >> u, --v, --u;
            char c;
            cin >> c;
            sub(v, u);
            gr[v][u] = c;
            add(v, u);
        } else if (tp == '-') {
            int v, u;
            cin >> v >> u, --v, --u;
            sub(v, u);
            gr[v][u] = 0;
            add(v, u);
        } else {
            int k;
            cin >> k;
            if (k % 2 == 0)
                cout << (cnt_even ? "YES" : "NO") << "\n";
            else
                cout << (cnt_odd ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}