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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());


int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    if (n * n < k)  {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> b(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!b[i][j] && k > 0) {
                if (i == j) {
                    b[i][j] = 1;
                    --k;
                } else {
                    if (k >= 2) {
                        b[i][j] = 1;
                        b[j][i] = 1;
                        k -= 2;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}