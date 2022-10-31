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

void solve() {
    string input_string;
    cin >> input_string;
    if (*min_element(all(input_string)) == *max_element(all(input_string))) {
        cout << input_string << "\n";
        return;
    }
    vector<int> cnt(26);
    for (char c : input_string) {
        cnt[c - 'a']++;
    }
    forn (i, 0, 26) {
        if (cnt[i] == 1) {
            cout << (char)(i + 'a');
            forn (j, 0, 26) {
                if (i != j) {
                    cout << string(cnt[j], j + 'a');
                }
            }
            cout << "\n";
            return;
        }
    }
    auto solve_same = [&](int zero) {
        auto cur_cnt = cnt;
        if (cur_cnt[zero] < 2) {
            return false;
        }
        cur_cnt[zero] -= 2;

        multiset<int> everything;
        multiset<int> non_zeros;
        forn (i, 0, 26) {
            if (i != zero) {
                forn (_, 0, cur_cnt[i]) {
                    non_zeros.insert(i);
                }
            }
            forn (_, 0, cur_cnt[i]) {
                everything.insert(i);
            }
        }
        if (non_zeros.size() < cur_cnt[zero]) {
            return false;
        }

        cout << string(2, zero + 'a');
        int prev = zero;
        while (!everything.empty()) {
            int cur;
            if (prev == zero) {
                cur = *non_zeros.begin();
                non_zeros.erase(non_zeros.begin());
                everything.erase(everything.find(cur));
            } else {
                if (cur_cnt[zero] && (non_zeros.empty() || zero < *non_zeros.begin())) {
                    cur = zero;
                    cur_cnt[zero]--;
                    everything.erase(everything.find(cur));
                } else {
                    if (cur_cnt[zero] == non_zeros.size() + 1) {
                        cur_cnt[zero]--;
                        cur = zero;
                        everything.erase(everything.find(cur));
                    } else {
                        cur = *non_zeros.begin();
                        non_zeros.erase(non_zeros.begin());
                        everything.erase(everything.find(cur));
                    }
                }
            }
            cout << (char)(cur + 'a');
            prev = cur;
        }
        return true;
    };
    auto solve_diff = [&](int zero, int one) {
        auto cur_cnt = cnt;
        if (cur_cnt[zero] < 1) {
            return false;
        }
        cur_cnt[zero]--;
        if (cur_cnt[one] < 1) {
            return false;
        }
        cur_cnt[one]--;

        cout << (char)(zero + 'a') << (char)(one + 'a');

        bool between_found = false;
        forn (i, zero + 1, one) {
            if (cur_cnt[i]) {
                between_found = true;
            }
        }
        if (between_found) {
            forn (i, 0, 26) {
                cout << string(cur_cnt[i], i + 'a');
            }
            return true;
        }

        int greater_found = -1;
        forn (i, one + 1, 26) {
            if (cur_cnt[i]) {
                greater_found = i;
                break;
            }
        }
        if (greater_found != -1) {
            forn (i, 0, 26) {
                cout << string(cur_cnt[i], i + 'a');
                if (i == zero) {
                    cout << (char)(greater_found + 'a');
                    cur_cnt[greater_found]--;
                }
            }
            return true;
        }
        forn (i, 0, 26) {
            if (i == zero) {
                cout << string(cur_cnt[one], one + 'a');
            } else if (i == one) {
                cout << string(cur_cnt[zero], zero + 'a');
            } else {
                cout << string(cur_cnt[i], i + 'a');
            }
        }
        return true;
    };
    forn (zero, 0, 26) {
        forn (one, 0, 26) {
            if (zero == one) {
                if (solve_same(zero)) {
                    cout << "\n";
                    return;
                }
            } else {
                if (solve_diff(zero, one)) {
                    cout << "\n";
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}