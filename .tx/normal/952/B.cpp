#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;
template <typename T> using vc = std::vector<T>;

string ask(int n) {
    cout << n << endl;
    string s;
    getline(cin, s);
    return s;
}

void solve(istream& cin, ostream& cout) {
    rep(i, 0, 10) {
        string s = ask(i);
        if (s == "don't even" || s == "terrible" || s == "worse" || s == "go die in a hole") {
            cout << "grumpy" << endl;
            return;
        }
        if (s[i] == 'd' || s == "not bad" || s == "great!" || s == "great" || s == "cool") {
            cout << "normal" << endl;
            return;
        }
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
//    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}