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
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 100100;
const int MAXM = 11;

int p[MAXM][MAXN];
int q[MAXM][MAXN];

struct Person {
    int x, y, id;
};

bool operator<(const Person &a, const Person &b) {
    return a.x - a.y < b.x - b.y;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<Person> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }

    vector<ll> res(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        int cur = min(a[u].x + a[v].y, a[u].y + a[v].x);
        res[u] -= cur;
        res[v] -= cur;
    }
    sort(all(a));

    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        res[a[i].id] += cur + (ll)(n - i - 1) * a[i].x;
        cur += a[i].x;
    }
    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        res[a[i].id] += cur + (ll)i * a[i].y;
        cur += a[i].y;
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}