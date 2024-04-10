#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

bool ask(const vector<int>& num, int l, int r) {
    cout << "? " << r - l << " ";
    for (int i = l; i < r; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    string ans;
    cin >> ans;
    return (ans == "YES");
}

bool guess(int x) {
    cout << "! " << x << endl;
    string ans;
    cin >> ans;
    return (ans == ":)");
}

void solve() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        num[i] = i + 1;
    }
    while (num.size() > 3) {
//        for (int x : num) {
//            cerr << " " << x;
//        }
        cerr << endl;
        int sz = num.size();
        int m2 = sz / 2;
        int m1 = m2 / 2;
        int m3 = (m2 + sz) / 2;
        bool k1 = ask(num, 0, m2);
        bool k2 = ask(num,m1, m3);
        vector<int> new_num;
        if (k1 || !k2) {
            for (int i = 0; i < m1; i++) {
                new_num.pb(num[i]);
            }
        }
        if (k1 || k2) {
            for (int i = m1; i < m2; i++) {
                new_num.pb(num[i]);
            }
        }
        if (!k1 || k2) {
            for (int i = m2; i < m3; i++) {
                new_num.pb(num[i]);
            }
        }
        if (!k1 || !k2) {
            for (int i = m3; i < sz; i++) {
                new_num.pb(num[i]);
            }
        }
        num.swap(new_num);
    }
    if (num.size() == 3) {
        bool ans;
        ans = ask(num, 0, 1);
        if (ans) {
            ans = guess(num[0]);
            if (ans) {
                return;
            }
            ans = ask(num, 1, 2);
            if (ans) {
                guess(num[1]);
            } else {
                guess(num[2]);
            }
            return;
        } else {
            ans = ask(num, 0, 1);
            if (ans) {
                ans = guess(num[0]);
                if (ans) {
                    return;
                }
                ans = ask(num, 1, 2);
                if (ans) {
                    guess(num[1]);
                } else {
                    guess(num[2]);
                }
                return;
            } else {
                num = {num[1], num[2]};
            }
        }
    }
    bool ok = guess(num[0]);
    if (!ok && num.size() == 2) {
        guess(num[1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}