#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = sz(s);
    vector<vector<int>> p(n, vector<int> (2));
    p[n - 2][0] = 1;
    p[n - 3][1] = 1;
    for (int i = n - 4; i >= 0; --i) {
        if (p[i + 2][1])
            p[i][0] = 1;
        if (p[i + 3][0])
            p[i][1] = 1;

        if (p[i + 3][1] && s.substr(i, 3) != s.substr(i + 3, 3))
            p[i][1] = 1;

        if (p[i + 2][0] && s.substr(i, 2) != s.substr(i + 2, 2))
            p[i][0] = 1;
    }
    map<string, int> m;
    vector<string> ans;
    for (int i = n - 1; i >= 5; --i) {
        if (i + 2 <= n) {
            if (m[s.substr(i, 2)] != 1) {
                if (p[i][0]) {
                    ans.push_back(s.substr(i, 2));
                    m[s.substr(i, 2)] = 1;
                }
            }
        }
        if (i + 3 <= n) {
            if (m[s.substr(i, 3)] != 1) {
                if (p[i][1]) {
                    ans.push_back(s.substr(i, 3));
                    m[s.substr(i, 3)] = 1;
                }
            }
        }
    }
    sort(all(ans));
    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i] << endl;



}