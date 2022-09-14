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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;
typedef pair<ll, int> pli;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rnd(1);

const int MAXN = 1000100;
int cnt[MAXN];
int dp[2][5][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        ++cnt[x];
    }
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        memset(dp[cur ^ 1], 0, sizeof(dp[cur ^ 1]));
        for (int a = 0; a <= 4; ++a) {
            for (int b = 0; b <= 2; ++b) {  
                for (int c = 0; c <= 2; ++c) {  
                    if (cnt[i] < a + c || cnt[i + 1] < b + c || cnt[i + 2] < c) {
                        continue;
                    }

                    int aa = b + c;
                    int bb = c;

                    dp[cur ^ 1][aa][bb] = max(dp[cur ^ 1][aa][bb], dp[cur][a][b] + c + (cnt[i] - a - c) / 3);

                }
            }
        }

        cur ^= 1;
    }

    cout << dp[cur][0][0] << endl;
}