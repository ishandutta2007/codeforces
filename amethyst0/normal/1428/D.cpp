#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

const int maxn = (int)1e5 + 10;
int v[maxn];

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    while (n > 0 && v[n - 1] == 0) {
        n--;
    }

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    if (v[n - 1] > 1) {
        cout << -1 << '\n';
        return 0;
    }

    int ps = n;

    vector <pii> ans;
    vector <int> one;
    vector <int> st;
    vector <int> th;

    vector <int> two;

    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == 0) {
            continue;
        }

        if (v[i] == 1) {
            ps--;
            one.push_back(ps);
            st.push_back(i);
            ans.push_back(mp(ps, i));
            continue;
        }

        if (v[i] == 2) {
            if (one.empty()) {
                cout << -1 << '\n';
                return 0;
            }
            ans.push_back(mp(one.back(), i));
            two.push_back(i);
            one.pop_back();
            st.pop_back();
            continue;
        }

        ps--;

        ans.push_back(mp(ps, i));

        if (!th.empty()) {
            ans.push_back(mp(ps, th.back()));
            th.pop_back();
        } else if (!two.empty()) {
            ans.push_back(mp(ps, two.back()));
            two.pop_back();
        }
        else if (!one.empty()) {
            ans.push_back(mp(ps, st.back()));
            st.pop_back();
            one.pop_back();
        }

        th.push_back(i);
    }

    cout << ans.size() << '\n';

    for (auto f : ans) {
        printf("%d %d\n", f.first + 1, f.second + 1);
    }
}