#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef unsigned int uint;

mt19937 rnd(random_device{}());


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
                
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<pair<int, int>> p;

    stack<int> st;

    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') {
            p.push_back({st.top(), i});
            st.pop();
        } else {
            st.push(i);
        }
    }

    vector<int> used(n);

    for (int i = 0; i < k / 2; ++i) {
        used[p[i].first] = 1;
        used[p[i].second] = 1;
    }

    string res;
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            res += s[i];
        }
    } 

    cout << res << endl;

}