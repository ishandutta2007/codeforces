
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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


    int tests;
    cin >> tests;
    for (int casenum = 1; casenum <= tests; casenum++) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int> > > ans;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string x;
            cin >> x;
            v.push_back(x);
        }
        while (n > 2) {
            for (int i = 0; i < m; i++) {
                if (v[n - 1][i] == '1') {
                    if (i == 0) {
                        ans.push_back({ {n - 1, i}, {n - 2, i}, {n - 2, i + 1} });
                        v[n - 1][i] ^= 1;
                        v[n - 2][i] ^= 1;
                        v[n - 2][i+1] ^= 1;
                    }
                    else {
                        ans.push_back({ {n - 1, i}, {n - 2, i}, {n - 2, i - 1} });
                        v[n - 1][i] ^= 1;
                        v[n - 2][i] ^= 1;
                        v[n - 2][i - 1] ^= 1;
                    }
                }

            }
            n--;
        }
        while (m > 2) {
            for (int i = 0; i < n; i++) {
                if (v[i][m-1] == '1') {
                    if (i == 0) {
                        ans.push_back({ {i, m-1}, {i, m-2}, {i+1, m-2} });
                        v[i][m-1] ^= 1;
                        v[i][m-2] ^= 1;
                        v[i+1][m-2] ^= 1;
                    }
                    else {
                        ans.push_back({ {i, m - 1}, {i, m - 2}, {i - 1, m - 2} });
                        v[i][m - 1] ^= 1;
                        v[i][m - 2] ^= 1;
                        v[i - 1][m - 2] ^= 1;
                    }
                }

            }
            m--;
        }
        int cnt = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (v[i][j] == '1') cnt++;
            }
        }
        if (cnt == 1) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (v[i][j] == '0') {
                        vector<pair<int, int> > v;
                        for (int ii = 0; ii < 2; ii++) {
                            for (int jj = 0; jj < 2; jj++) {
                                if(i != ii || j != jj) v.push_back({ ii, jj });
                            }
                        }
                        ans.push_back(v);
                    }
                }
            }
        }
        if (cnt == 2) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (v[i][j] == '1') {
                        vector<pair<int, int> > v;
                        for (int ii = 0; ii < 2; ii++) {
                            for (int jj = 0; jj < 2; jj++) {
                                if (i != ii || j != jj) v.push_back({ ii, jj });
                            }
                        }
                        ans.push_back(v);
                    }
                }
            }
        }
        if (cnt == 3) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (v[i][j] == '0') {
                        vector<pair<int, int> > v;
                        for (int ii = 0; ii < 2; ii++) {
                            for (int jj = 0; jj < 2; jj++) {
                                if (i != ii || j != jj) v.push_back({ ii, jj });
                            }
                        }
                        ans.push_back(v);
                    }
                }
            }
        }
        if (cnt == 4) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    if (v[i][j] == '1') {
                        vector<pair<int, int> > v;
                        for (int ii = 0; ii < 2; ii++) {
                            for (int jj = 0; jj < 2; jj++) {
                                if (i != ii || j != jj) v.push_back({ ii, jj });
                            }
                        }
                        ans.push_back(v);
                    }
                }
            }
        }
        cout << ans.size() << endl;
        for (auto p : ans) {
            cout << p[0].first+1 << " " << 1+p[0].second << " " << p[1].first+1 << " " << 1+p[1].second << " " << p[2].first+1 << " " << 1+p[2].second << endl;
        }
    }

}