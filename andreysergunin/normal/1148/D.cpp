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
#include <chrono>
#include <climits>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;
// mt19937 rnd(1);

struct Data {
    int x, y, id;
};

bool operator<(const Data &a, const Data &b) {
    return a.y > b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);


    int n;
    cin >> n;
    vector<Data> u, v;

    for (int i = 0; i < n; ++i) {
        int x, y, id = i + 1;
        cin >> x >> y;
        if (x < y) {
            u.push_back({x, y, id});
        } else if (x > y) {
            v.push_back({-x, -y, id});
        }
    }

    sort(all(u));
    sort(all(v));

    if (sz(u) <= sz(v)) {
        swap(u, v);
    }
    
    cout << sz(u) << endl;

    for (Data d : u) {
        cout << d.id << " ";
    }
    cout << endl;

}