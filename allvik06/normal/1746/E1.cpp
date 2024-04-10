#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>
#include <complex>
#include <functional>
#include <unordered_map>

using namespace std;

inline int ask(const vector <int>& cur) {
    cout << "? " << (int)cur.size() << " ";
    for (int i : cur) cout << i << " ";
    cout << endl;
    string s;
    cin >> s;
    if (s == "NO") return 0;
    return 1;
}

inline void print(int x) {
    cout << "! " << x << endl;
    string s;
    cin >> s;
    if (s == ":)") exit(0);
}

void calc(vector <int>& cur) {
    if ((int)cur.size() <= 2) {
        for (int i : cur) print(i);
    }
    if ((int)cur.size() == 3) {
        int rs1 = ask({cur[0]});
        if (rs1 == 0) {
            int rs2 = ask({cur[0]});
            if (rs2 == 0) {
                print(cur[1]);
                print(cur[2]);
            }
        }
        int rs = ask({cur[0], cur[1]});
        if (rs == 1) {
            print(cur[0]);
            print(cur[1]);
        } else {
            print(cur[0]);
            print(cur[2]);
        }
    }
    vector <int> f, s;
    int l = (int)cur.size();
    for (int i = 0; i < l; ++i) {
        if (i < l / 2) f.push_back(cur[i]);
        else s.push_back(cur[i]);
    }
    vector <int> flex1, flex2;
    int l1 = (int)f.size(), l2 = (int)s.size();
    for (int i = 0; i < l1; ++i) {
        if (i < l1 / 2) flex1.push_back(f[i]);
        else flex2.push_back(f[i]);
    }
    for (int i = 0; i < l2; ++i) {
        if (i < l2 / 2) flex1.push_back(s[i]);
        else flex2.push_back(s[i]);
    }
    int rs1 = ask(flex1);
    int rs2 = ask(f);
    if (rs1 == 0 && rs2 == 0) {
        for (int i = 0; i < l2 / 2; ++i) {
            flex2.push_back(s[i]);
        }
        calc(flex2);
    } else if (rs1 == 1 && rs2 == 0) {
        for (int i = l2 / 2; i < l2; ++i) {
            flex1.push_back(s[i]);
        }
        calc(flex1);
    } else if (rs1 == 0 && rs2 == 1) {
        for (int i = 0; i < l1 / 2; ++i) {
            flex2.push_back(f[i]);
        }
        calc(flex2);
    } else {
        for (int i = l1 / 2; i < l1; ++i) {
            flex1.push_back(f[i]);
        }
        calc(flex1);
    }
}

inline void solve() {
    int n;
    cin >> n;
    vector <int> a;
    for (int i = 1; i <= n; ++i) a.push_back(i);
    calc(a);
}

signed main(int32_t argc, char **argv) {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        //cin >> t;
        while (t--) {
            solve();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */