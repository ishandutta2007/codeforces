#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
#include <set>
#include <map>
#include <cassert>
#include <string>
#include <iomanip>
#include <array>
#include <deque>
#include <cmath>
#include <complex>
#include <queue>
#include <iomanip>

using namespace std;
string s, t;

inline void print_ans1(int n, string now) {
    string tmp;
    if (n == 1) {
        tmp = now;
    } else {
        tmp = now + now;
    }
    for (int i = 0; i < (int)tmp.size() - 1; ++i) {
        if (tmp.substr(i, 2) == s || tmp.substr(i, 2) == t) return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) cout << now.substr(0, 3);
    exit(0);
}

inline void print_ans2(int n, string now) {
    string tmp;
    if (n == 1) {
        tmp = now;
    } else {
        for (int i = 0; i < 3; ++i) {
            tmp += now[i];
            tmp += now[i];
        }
    }
    for (int i = 0; i < (int)tmp.size() - 1; ++i) {
        if (tmp.substr(i, 2) == s || tmp.substr(i, 2) == t) return;
    }
    cout << "YES\n";
    for (int i = 0; i < 3 * n; ++i) cout << now[i / n];
    exit(0);
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int n;
    cin >> n >> s >> t;
    print_ans1(n, "abc");
    print_ans1(n, "acb");
    print_ans1(n, "bac");
    print_ans1(n, "bca");
    print_ans1(n, "cab");
    print_ans1(n, "cba");
    print_ans2(n, "abc");
    print_ans2(n, "acb");
    print_ans2(n, "bac");
    print_ans2(n, "bca");
    print_ans2(n, "cab");
    print_ans2(n, "cba");
    cout << "NO";
}

/*

 */