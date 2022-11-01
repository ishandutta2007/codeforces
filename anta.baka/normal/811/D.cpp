#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1, '*'));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];

    bool turnL = false, turnU = false;
    if(a[0][1] != '*') {
        cout << 'L' << endl;
        int i, j; cin >> i >> j; i--; j--;
        if(a[i][j] == 'F') return 0;
        if(j == 1) {
            turnL = true;
            cout << 'R' << endl;
            cin >> i >> j; i--; j--;
        }
        for(int k = 0; ; k++) {
            if(a[i + 1][j] != '*') {
                cout << 'U' << endl;
                cin >> i >> j; i--; j--;
                if(a[i][j] == 'F') return 0;
                if(i == 1) {
                    turnU = true;
                    cout << 'D' << endl;
                    cin >> i >> j; i--; j--;
                }
                while(k--) {
                    //cout << "kek" << endl;
                    cout << (turnL ? 'R' : 'L') << endl;
                    cin >> i >> j; i--; j--;
                }
                break;
            }
            cout << (turnL ? 'L' : 'R') << endl;
            cin >> i >> j; i--; j--;
            if(a[i][j] == 'F') return 0;
        }
    } else {
        cout << 'U' << endl;
        int i, j; cin >> i >> j; i--; j--;
        if(a[i][j] == 'F') return 0;
        if(i == 1) {
            turnU = true;
            cout << 'D' << endl;
            cin >> i >> j; i--; j--;
        }
        for(int k = 0; ; k++) {
            if(a[i][j + 1] != '*') {
                cout << 'L' << endl;
                cin >> i >> j; i--; j--;
                if(a[i][j] == 'F') return 0;
                if(j == 1) {
                    turnL = true;
                    cout << 'R' << endl;
                    cin >> i >> j; i--; j--;
                }
                while(k--) {
                    cout << (turnU ? 'D' : 'U') << endl;
                    cin >> i >> j; i--; j--;
                }
                break;
            }
            cout << (turnU ? 'U' : 'D') << endl;
            cin >> i >> j; i--; j--;
            if(a[i][j] == 'F') return 0;
        }
    }

    //cout << turnL << ' ' << turnU << endl; //return 0;

    const int di[] = {0, 0, 1,-1};
    const int dj[] = {1,-1, 0, 0};
    vector<vector<bool>> was(n, vector<bool>(m, false));
    vector<vector<char>> prev(n, vector<char>(m));
    queue<pair<int, int>> q;
    q.push({0, 0});
    was[0][0] = true;
    while(!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        for(int w = 0; w < 4; w++) {
            int i1 = i + di[w], j1 = j + dj[w];
            if(i1 == -1 || j1 == -1 || i1 == n || j1 == m || was[i1][j1] || a[i1][j1] == '*') continue;
            was[i1][j1] = true;
            q.push({i1, j1});
            if(w == 0) prev[i1][j1] = 'R';
            else if(w == 1) prev[i1][j1] = 'L';
            else if(w == 2) prev[i1][j1] = 'D';
            else prev[i1][j1] = 'U';
        }
    }

    /*for(int i = 0; i < n; i++, cout << endl)
        for(int j = 0; j < m; j++)
            cout << (was[i][j] ? prev[i][j] : '-');
    cout << endl;*/
    //return 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == 'F') {
                vector<char> path;
                while(i || j) {
                    path.push_back(prev[i][j]);
                    if(prev[i][j] == 'U') i++;
                    else if(prev[i][j] == 'D') i--;
                    else if(prev[i][j] == 'L') j++;
                    else if(prev[i][j] == 'R') j--;
                    //cout << i << ' ' << j << endl;
                }
                for(int k = 0; k < path.size(); k++) {
                    if(turnL) {
                        if(path[k] == 'L') path[k] = 'R';
                        else if(path[k] == 'R') path[k] = 'L';
                    }
                    if(turnU) {
                        if(path[k] == 'U') path[k] = 'D';
                        else if(path[k] == 'D') path[k] = 'U';
                    }
                }
                reverse(path.begin(), path.end());
                int x, y;
                for(char ch : path) cout << ch << endl, cin >> x >> y;
                return 0;
            }
}