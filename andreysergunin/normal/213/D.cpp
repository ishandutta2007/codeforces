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
#include <complex>
#include <bitset>
 
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int MAXN = 222;

vector<int> g[MAXN];
int d[MAXN];
int k[MAXN];
bool used[MAXN];

vector<int> c[3];

struct Point {
    double x, y;
};

Point operator+(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

Point operator*(const Point &a, double c) {
    return {a.x * c, a.y * c};
}

ostream &operator << (std::ostream &stream, const Point &a) {
    stream << a.x << " " << a.y;
    return stream;
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    vector<Point> star = {
        {3.830127018922193, 3.366025403784439},
        {-3.601321235851749, 10.057331467373021},
        {0.466045194906253, 19.192786043799030},
        {10.411264148588986, 18.147501411122495},
        {12.490381056766580, 8.366025403784439}
    };

    int n;
    cin >> n;

    cout << 4 * n + 1 << endl;


    cout.precision(15);
    
    cout << star[0] << endl;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < 5; ++j) {
            cout << star[j] + (star[2] - star[0]) * i << endl;
        } 
    }

    cout << "1 2 3 4 5" << endl;
    for (int i = 1; i < n; ++i) {
        cout << 3 + 4 * (i - 1) << " ";
        cout << 2 + 4 * i << " ";
        cout << 3 + 4 * i << " ";
        cout << 4 + 4 * i << " ";
        cout << 5 + 4 * i << " ";
        cout << endl;
    }

    vector<int> res;

    res.push_back(1);
    for (int i = 0; i < n; ++i) {
        res.push_back(3 + 4 * i);
    }

    for (int i = n - 1; i >= 0; --i) {
        res.push_back(5 + 4 * i);
        res.push_back(2 + 4 * i);
        res.push_back(4 + 4 * i);
        if (i > 0) {
            res.push_back(3 + 4 * i - 4);
        } else {
            res.push_back(1);
        }
    }


    for (int i = 0; i < sz(res); ++i) {
        cout << res[i] << " ";
    }

    cout << endl;
}