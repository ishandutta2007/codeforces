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

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int n, k;
vector <int> a;
int dp[500100][28];
pair <int, int> minpref[30];
pair <int, int> minsuf[30];
int p[500100][28];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    scanf(" ");
    for (int i = 0; i < n; ++i) {
        char c;
        scanf(" %c ", &c);
        a.pb(c - 'A');
    }
    for (int i = 0; i < k; ++i)
        dp[0][i] = 1;
    dp[0][a[0]] = 0;
    for (int i = 1; i < n; ++i) {
        minpref[0] = mp(dp[i - 1][0], 0);
        for (int j = 1; j < k; ++j)
            minpref[j] = min(minpref[j - 1], mp(dp[i - 1][j], j));
        minsuf[k - 1] = mp(dp[i - 1][k - 1], k - 1);
        for (int j = k - 2; j >= 0; --j)
            minsuf[j] = min(minsuf[j + 1], mp(dp[i - 1][j], j));
        for (int j = 0; j < k; ++j) {
            if (j != a[i]) {
                if (j == 0) {
                    dp[i][j] = 1 + minsuf[1].first;
                    p[i][j] = minsuf[1].second;
                }
                else if (j == k - 1) {
                    dp[i][j] = 1 + minpref[k - 2].first;
                    p[i][j] = minpref[k - 2].second;
                }
                else {
                    if (minpref[j - 1] < minsuf[j + 1]) {
                        dp[i][j] = 1 + minpref[j - 1].first;
                        p[i][j] = minpref[j - 1].second;
                    }
                    else {
                        dp[i][j] = 1 + minsuf[j + 1].first;
                        p[i][j] = minsuf[j + 1].second;
                    }
                }
            }
            else {
                if (j == 0) {
                    dp[i][j] = minsuf[1].first;
                    p[i][j] = minsuf[1].second;
                }
                else if (j == k - 1) {
                    dp[i][j] = minpref[k - 2].first;
                    p[i][j] = minpref[k - 2].second;
                }
                else {
                    if (minpref[j - 1] < minsuf[j + 1]) {
                        dp[i][j] = minpref[j - 1].first;
                        p[i][j] = minpref[j - 1].second;
                    }
                    else {
                        dp[i][j] = minsuf[j + 1].first;
                        p[i][j] = minsuf[j + 1].second;
                    }
                }
            }
        }
    }
    int res = inf;
    for (int i = 0; i < k; ++i)
        res = min(res, dp[n - 1][i]);
    cout << res << endl;
    a.clear();
    for (int i = 0; i < 26; ++i)
        if (dp[n - 1][i] == res) {
            int j = n - 1;
            int cur = i;
            while(j >= 0) {
                a.pb(cur + 'A');
                cur = p[j][cur];
                --j;
            }
            for (int i = a.size() - 1; i >= 0; --i)
                printf("%c", char(a[i]));
            cout << endl;
            return 0;
        }
    return 0;
}