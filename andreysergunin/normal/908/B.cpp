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

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

int n, m;
vector<string> b;

bool correct(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return 0;
    }
    return b[x][y] != '#';
}

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);        


    cin >> n >> m;
    b.resize(n);

    int sx, sy;
    int fx, fy;

    for (int i = 0; i < n; ++i) {
        cin >> b[i];

        for (int j = 0; j < m; ++j) {
            if (b[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (b[i][j] == 'E') {
                fx = i;
                fy = j;
            }
        }   
    }

    vector<int> p = {0, 1, 2, 3};

    string s;
    cin >> s;


    int res = 0;

    for (; ; ) {    
        int cx = sx;
        int cy = sy;

        bool ok = true;
        for (int i = 0; i < sz(s); ++i) {
            int type = s[i] - '0';
            cx += dx[p[type]];
            cy += dy[p[type]];
            if (cx == fx && cy == fy) {
                break;
            }
            if (!correct(cx, cy)) {
                ok = false;
                break;
            }
        }

        res += (ok && cx == fx && cy == fy);

        if (!next_permutation(all(p))) {
            break;
        }
    }

    cout << res << endl;

}