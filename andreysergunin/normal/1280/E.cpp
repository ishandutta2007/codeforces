#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;  

    int tests = 1;
    cin >> tests;

    while (tests--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------------

struct Resistor {
    int mult;
    vector<int> id;
};

void solve() {
    int r;
    cin >> r;
    string s;
    getline(cin, s);

    // cout << r << " " << s << endl;

    vector<Resistor> st;
    vector<char> symb;

    int k = 0;

    int m = 0;

    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == ' ') {
            continue;
        }   

        if (s[i] == '*') {
            st.push_back({1, {m++}});
            ++k;
            continue;
        } else if (s[i] != ')') {
            symb.push_back(s[i]);
            continue;
        }

        while (symb.back() != '(') {
            if (symb.back() == 'S') {
                if (st[k - 2].mult > st[k - 1].mult) {
                    swap(st[k - 1], st[k - 2]);
                }
                st.pop_back();
                --k;
            } else {
                if (sz(st[k - 2].id) < sz(st[k - 1].id)) {
                    swap(st[k - 1], st[k - 2]);
                }
                st[k - 2].mult += st[k - 1].mult;

                for (int id : st[k - 1].id) {
                    st[k - 2].id.push_back(id);
                }
                st.pop_back();
                --k;
            }

            symb.pop_back();
        }

        symb.pop_back();
    }    
    assert(sz(st) == 1);

    vector<int> res(m);

    for (int id : st[0].id) {
        res[id] = st[0].mult;
    }

    cout << "REVOLTING ";

    for (ll x : res) {
        cout << x * r << " ";
    }
    cout << endl;

}