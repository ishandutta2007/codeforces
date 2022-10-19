
using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;

    double dp[101][10005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int> > v;
    double tot = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
        tot += ((double)y / 2.0);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 10005; j >=0; j--) {
        for (int k = 0; k <= n; k++) {
            
                if (i == 0 && j == 0 && k==0) {
                    dp[k][j] = 0;
                    continue;
                }
                if (i == 0) {
                    dp[k][j] = -1000000;
                    continue;
                }
                if (j == 0 && k!=0) {
                    dp[k][j] = -1000000;
                    continue;
                }
                if (k == 0 && j!=0) {
                    dp[k][j] = -1000000;
                    continue;
                }
                if (k == 0 && j == 0) continue;
                int sz = v[i - 1].first;
                double wat = v[i - 1].second;
                dp[k][j] = max(dp[k][j] , dp[k - 1][max(j - sz, 0)] + (wat/2));
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        double best = 0;
        for (double j = 0; j < 10005; j++) {
            //if(dp[k][(int) j] > 0)
            //cout << k << " " << j << " " << dp[k][(int) j]+tot << endl;
            best = max(best, min(dp[k][(int) j]+tot, j));
        }
        cout << best << " ";
    }


}