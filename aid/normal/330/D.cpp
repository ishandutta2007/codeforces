#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int main() {
    ios_base::sync_with_stdio(0);
    int r, c;
    cin >> r >> c;
    pair<int, int> s, e;
    vector< vector<char> > f(r, vector<char>(c));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
            cin >> f[i][j];
            if(f[i][j] == 'S') {
                s = make_pair(i, j);
                f[i][j] = '0';
            }
            if(f[i][j] == 'E') {
                e = make_pair(i, j);
                f[i][j] = '0';
            }
        }
    vector< vector<int> > v(r, vector<int>(c, INF));
    vector< vector<char> > used(r, vector<char>(c));
    queue< pair<int, int> > q;
    q.push(e);
    v[e.first][e.second] = 0;
    used[e.first][e.second] = true;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if(p.second > 0 && !used[p.first][p.second - 1] &&
           f[p.first][p.second - 1] != 'T') {
            q.push(make_pair(p.first, p.second - 1));
            v[p.first][p.second - 1] = v[p.first][p.second] + 1;
            used[p.first][p.second - 1] = true;
        }
        if(p.first > 0 && !used[p.first - 1][p.second] &&
           f[p.first - 1][p.second] != 'T') {
            q.push(make_pair(p.first - 1, p.second));
            v[p.first - 1][p.second] = v[p.first][p.second] + 1;
            used[p.first - 1][p.second] = true;
        }
        if(p.second < c - 1 && !used[p.first][p.second + 1] &&
           f[p.first][p.second + 1] != 'T') {
            q.push(make_pair(p.first, p.second + 1));
            v[p.first][p.second + 1] = v[p.first][p.second] + 1;
            used[p.first][p.second + 1] = true;
        }
        if(p.first < r - 1 && !used[p.first + 1][p.second] &&
           f[p.first + 1][p.second] != 'T') {
            q.push(make_pair(p.first + 1, p.second));
            v[p.first + 1][p.second] = v[p.first][p.second] + 1;
            used[p.first + 1][p.second] = true;
        }
    }
    int t = v[s.first][s.second];
    int ans = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(f[i][j] != 'T' && v[i][j] <= t)
                ans += f[i][j] - '0';
    cout << ans << '\n';
}