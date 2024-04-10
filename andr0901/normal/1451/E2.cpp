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

int ask(string type, int i, int j) {
    cout << type << " " << i + 1 << " " << j + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

vector <int> xors;

int get_xor(int i, int j) {
    cerr << i << " " << j << ": " << (xors[i] ^ xors[j]) << "\n";
    return xors[i] ^ xors[j];
}

int solve(vector <int>& idxs) {
    int xor01 = get_xor(idxs[0], idxs[1]);
    int xor02 = get_xor(idxs[0], idxs[2]);
    int xor12 = xor01 ^ xor02;
    int and01 = 0;
    int and02 = ask("AND", idxs[0], idxs[2]);
    int and12 = ask("AND", idxs[1], idxs[2]);
    vector <int> ans(sz(idxs));
    forn (i, 0, 16) {
        int xor01_cur = (xor01 >> i) & 1;
        int xor02_cur = (xor02 >> i) & 1;
        int xor12_cur = (xor12 >> i) & 1;
        int and01_cur = (and01 >> i) & 1;
        int and02_cur = (and02 >> i) & 1;
        int and12_cur = (and12 >> i) & 1;
        forn (zero, 0, 2) {
            forn (one, 0, 2) {
                forn (two, 0, 2) {
                    if ((zero ^ one) == xor01_cur &&
                        (zero ^ two) == xor02_cur &&
                        (one ^ two) == xor12_cur &&
                        (zero & one) == and01_cur &&
                        (zero & two) == and02_cur &&
                        (one & two) == and12_cur) {
                            ans[0] |= (zero << i);
                            ans[1] |= (one << i);
                            ans[2] |= (two << i);
                            cerr << i << " ";
                        }
                }
            }
        }
    }
    return ans[0];
}

int main() {
    int n;
    cin >> n;
    map <int, int> used;
    xors.resize(n);
    int val = -1, idx = -1;
    forn (i, 1, n) {
        xors[i] = ask("XOR", 0, i);
        if (xors[i] == 0 && idx == -1) {
            val = ask("AND", 0, i);
            idx = i;
        }
        if (used.find(xors[i]) != used.end() && idx == -1) {
            val = ask("AND", i, used[xors[i]]);
            idx = i;
        }
        used[xors[i]] = i;
    };
    vector <int> ans(n);
    if (idx != -1) {
        forn (i, 0, n)
            ans[i] = get_xor(i, idx) ^ val;
    } else {
        forn (i, 0, n)
            if (xors[i] == n - 1) {
                vector <int> idxs = {i, 0};
                forn (j, 1, n)
                    if (j != i) {
                        idxs.pb(j);
                        break;
                    }
                int val = solve(idxs);
                forn (j, 0, n)
                    ans[j] = get_xor(i, j) ^ val;
                break;
            }
    }
    cout << "! " << ans << endl;
}