#include <stdio.h>
#include <iostream>
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
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int P = 1e9 + 7;
const int INF = 1e9;

vector<int> p;


void swp(int i, int j) {
    swap(p[i], p[j]);
    cout << i + 1 << " " << j + 1 << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    if (n * (n - 1) % 4 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    p.resize(n);
    for (int i = 0; i < n; ++i)
        p[i] = i;

    cout << "YES" << endl;

    bool forbid = false;
    for (int i = 0; i < n - 1; ++i) {
        if (p[i] == i) {
            if (forbid) {
                swp(i, i + 2);
                swp(i + 2, i + 3);
                for (int j = i + 4; j < n; ++j)
                    swp(i, j);
                swp(i, i + 3);
                forbid = true;
            } else {
                swp(i, i + 1);
                swp(i + 1, i + 2);
                for (int j = i + 3; j < n; ++j)
                    swp(i, j);
                swp(i, i + 2);
                forbid = true;
            }
        } else {
            if (forbid) {
                int k = -1;
                for (int j = i + 2; j < n; ++j) {
                    if (p[j] == i) {
                        k = j;
                        continue;
                    }
                    swp(i, j);
                }
                swp(i, k);
            } else {
                int k = -1;
                for (int j = i + 1; j < n; ++j) {
                    if (p[j] == i) {
                        k = j;
                        continue;
                    }
                    swp(i, j);
                }
                swp(i, k);
            }
            forbid = false;
        }
    }

    for (int i = 0; i < n; ++i) {
        assert(i == p[i]);
    }
    return 0;
}