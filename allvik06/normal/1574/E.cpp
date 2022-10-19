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
#define int long long
const int mod = 998244353;

inline int power(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

void solve1() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int>> a(n, vector <int> (2)), b(m, vector <int> (2));
    int cnt2_s = n, cnt1_s = 0, cnt0_s = 0;
    int cnt2_c = m, cnt1_c = 0, cnt0_c = 0;
    int sum0 = 0, sum1 = 0;
    map <pair <int, int>, int> val;

    auto relax_string = [&](int x, int val, int pl) {
        if (a[x][val] == 0) {
            if (a[x][val ^ 1] == 0) cnt2_s--;
            else cnt1_s--;
        } else {
            if (a[x][val ^ 1] == 0) cnt1_s--;
            else cnt0_s--;
        }
        a[x][val] += pl;
        if (a[x][val] == 0) {
            if (a[x][val ^ 1] == 0) cnt2_s++;
            else cnt1_s++;
        } else {
            if (a[x][val ^ 1] == 0) cnt1_s++;
            else cnt0_s++;
        }
    };

    auto relax_column = [&](int x, int val, int pl) {
        if (b[x][val] == 0) {
            if (b[x][val ^ 1] == 0) cnt2_c--;
            else cnt1_c--;
        } else {
            if (b[x][val ^ 1] == 0) cnt1_c--;
            else cnt0_c--;
        }
        b[x][val] += pl;
        if (b[x][val] == 0) {
            if (b[x][val ^ 1] == 0) cnt2_c++;
            else cnt1_c++;
        } else {
            if (b[x][val ^ 1] == 0) cnt1_c++;
            else cnt0_c++;
        }
    };

    auto relax_point = [&](int x, int y, int val, int pl) {
        if (val == -1) return;
        relax_string(x, (val ^ y) & 1, pl);
        relax_column(y, (val ^ x) & 1, pl);
        int flex = (val ^ ((x & 1) + (y & 1))) & 1;
        if (flex == 0) sum0 += pl;
        else sum1 += pl;
    };

    while (k--) {
        int x, y, flex;
        cin >> x >> y >> flex; --x; --y;
        if (flex == -1) {
            int va = -1;
            if (val.count(make_pair(x, y))) va = val[make_pair(x, y)];
            relax_point(x, y, va, -1);
            val[make_pair(x, y)] = -1;
        } else if (flex == 0) {
            int va = -1;
            if (val.count(make_pair(x, y))) va = val[make_pair(x, y)];
            relax_point(x, y, va, -1);
            relax_point(x, y, 0, 1);
            val[make_pair(x, y)] = 0;
        } else {
            int va = -1;
            if (val.count(make_pair(x, y))) va = val[make_pair(x, y)];
            relax_point(x, y, va, -1);
            relax_point(x, y, 1, 1);
            val[make_pair(x, y)] = 1;
        }
        int ans = mod - (sum0 == 0) - (sum1 == 0);
        if (cnt0_s == 0) ans += power(2, cnt2_s);
        if (cnt0_c == 0) ans += power(2, cnt2_c);
        cout << ans % mod << "\n";
    }
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
            solve1();
        }
        //  while (true) {}
    } else {

    }
}

/*

 */