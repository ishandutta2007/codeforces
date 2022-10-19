#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    int ntest;
    cin >> ntest;

    while (ntest--) {
        int n;
        cin >> n;
        vector<string> s(n);
        for (string &e : s) cin >> e;
        vector<vector<char>> v(3);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] != '.') v[(i + j) % 3].push_back(s[i][j]);
            }
        }

        ii toChange;
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (3 * (v[i].size() + v[j].size()) <= 2 * (v[0].size() + v[1].size() + v[2].size())) toChange = {i, j};
            }
        }

        int sum = v[toChange.x].size() + v[toChange.y].size();
        int cnt0 = 0;
        for (int e : v[toChange.x]) cnt0 += (e == 'X');
        for (int e : v[toChange.y]) cnt0 += (e == 'O');
        if (cnt0 * 2 <= sum) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i + j) % 3 == toChange.x && s[i][j] == 'X') s[i][j] = 'O';
                    if ((i + j) % 3 == toChange.y && s[i][j] == 'O') s[i][j] = 'X';
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i + j) % 3 == toChange.x && s[i][j] == 'O') s[i][j] = 'X';
                    if ((i + j) % 3 == toChange.y && s[i][j] == 'X') s[i][j] = 'O';
                }
            }
        }

        for (int i = 0; i < n; i++) cout << s[i] << '\n';

    }

    return 0;
}