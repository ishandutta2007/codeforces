#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <numeric>
#include <map>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <random>
#include <sstream>
#include <string>
#include <memory>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const int N = 5e3 + 10;
const int MAX = 1e9 - 1;
const int M = 11;

ll cnt(int n) {
    ll ans = 0;
    if (n % 2) {
        ans += n / 2;
        n--;
    }
    return ans + ((ll)n / 2 - 1) * (ll)n / 2;
}

void solve() {
    vector<int> answer;
    ll n, m;
    cin >> n >> m;

    int k = 0;
    for (k = 0; k <= n + 1; ++k) {
        if (cnt(k) >= m) {
            break;
        }
    }
    if (k > n) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n - k; i++) {
        answer.push_back(MAX - 3 * N * i);
    }

    if (m == 0) {
        sort(answer.begin(), answer.end());
        for (auto el : answer) {
            cout << el << " ";
        }
        cout << endl;
        return;
    }

    ll base = cnt(k - 1);
    int last = k;
    while (true) {
        int start = last - (k - 1);
        if (base + (k - start) / 2 == m) {
            break;
        }
        last++;
    }
    
    for (int i = 1; i <= k - 1; ++i) {
        answer.push_back(i);
    }
    answer.push_back(last);

	sort(answer.begin(), answer.end());
	for (auto el : answer) {
		cout << el << " ";
	}
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    //    freopen("a.in", "r", stdin);
    solve();
}