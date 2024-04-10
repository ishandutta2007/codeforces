#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
#define count ololo
#define pow olol
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

const int prob[3] = {0, 4, 7};

int a[20];
bool dp[20][5];
vector <int64> res[20][5];
int64 pow[20];

void prec() {
    pow[0] = 1;
    for (int i = 1; i <= 18; ++i)
        pow[i] = pow[i - 1] * 10LL;
}

void solve(int64 x) {
    memset(a, 0, sizeof(a));
    memset(dp, 0, sizeof(dp));

    int n = 0;
    while (x) {
        a[n] = int(x % 10LL);
        x /= 10LL;
        ++n;
    }
    dp[0][0] = 1;
    res[0][0].clear();
    for (int j = 0; j < 6; ++j)
        res[0][0].push_back(0);

    for (int i = 0; i <= 18; ++i)
        for (int j = 0; j <= 4; ++j) {
            if (!dp[i][j])
                continue;
            vector <int> xi;
            xi.resize(6);
            for (xi[0] = 0; xi[0] < 3; ++xi[0])
                for (xi[1] = xi[0]; xi[1] < 3; ++xi[1])
                    for (xi[2] = xi[1]; xi[2] < 3; ++xi[2])
                        for (xi[3] = xi[2]; xi[3] < 3; ++xi[3])
                            for (xi[4] = xi[3]; xi[4] < 3; ++xi[4])
                                for (xi[5] = xi[4]; xi[5] < 3; ++xi[5]) {
                                    int sum = j;
                                    for (int y = 0; y < 6; ++y)
                                        sum += prob[xi[y]];
                                    if (sum % 10 != a[i])
                                        continue;
                                    if (dp[i + 1][sum / 10])
                                        continue;
                                    vector <int64> newres = res[i][j];
                                    for (int y = 0; y < 6; ++y)
                                        newres[y] += pow[i] * int64(prob[xi[y]]);
                                    dp[i + 1][sum / 10] = true;
                                    res[i + 1][sum / 10] = newres;
                                }
        }
    

    if (!dp[19][0]) {
        cout << -1 << "\n";
    }
    else {
        for (int i = 0; i < 6; ++i)
            cout << res[19][0][i] << " ";
        cout << "\n";
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    prec();
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int64 x;
        cin >> x;
        solve(x);
    }
    return 0;
}