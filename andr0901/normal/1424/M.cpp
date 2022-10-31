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

constexpr int N = 26;

vector <vector <bool>> gr;
vector <int> ord;
vector <int> used;

void dfs(int v) {
    used[v] = 1;
    forn (u, 0, N) {
        if (!gr[v][u])
            continue;
        if (used[u] == 1) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        } 
        if (!used[u]) {
            dfs(u);
        }
    }
    ord.pb(v);
    used[v] = 2;
}

const int MAXN = 105, MOD = 1e9 + 7, P = 41;


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <pair <int, vector <string>>> pages(n);
    forn (i, 0, n) {
        cin >> pages[i].fs;
        pages[i].sc.resize(k);
        forn (j, 0, k)
            cin >> pages[i].sc[j];
    }
    sort(all(pages), [](const auto& a, const auto& b) {
        return a.fs < b.fs;
    });
    vector <bool> letter_used(N);
    vector <string> words;
    forn (i, 0, n)
        for (auto s : pages[i].sc) {
            words.pb(s);
            for (char c : s) {
                letter_used[c - 'a'] = true;
            }
        }
    gr.resize(N, vector <bool> (N));
    forn (i, 0, sz(words) - 1) {
        int j = i + 1; {
            int k = 0;
            while (k < words[i].size() && k < words[j].size() && words[i][k] == words[j][k])
                ++k;
            if (k == words[i].size() || k == words[j].size()) {
                if (words[i].size() > words[j].size())
                    return cout << "IMPOSSIBLE", 0;
                continue;
            }
            int v = words[i][k] - 'a', u = words[j][k] - 'a';
            if (gr[u][v])
                return cout << "IMPOSSIBLE", 0;
            gr[v][u] = true;    
        }
    }
    used = vector <int> (N);
    forn (i, 0, N)
        if (!used[i])
            dfs(i);
    reverse(all(ord));
    for (int i : ord)
        if (letter_used[i])
            cout << static_cast<char>(i + 'a');
    return 0;
}