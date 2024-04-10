#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

string a[1111];
int d[1111][1111];

char dc[4] = {'D', 'L', 'R', 'U'};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, m, k);
    if (k % 2 != 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X') {
                sx = i;
                sy = j;
            }
        }
    }
    
    a[sx][sy] = '.';
    queue<pair<int, int> > q;
    q.push({sx, sy});
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            d[i][j] = 1e9;
        }
    }
    d[sx][sy] = 0;
    while (!q.empty()) {
        int vx = q.front().first;
        int vy = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int x = vx + dx[i];
            int y = vy + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] != '.') {
                continue;
            }
            if (d[x][y] > d[vx][vy] + 1) {
                d[x][y] = d[vx][vy] + 1;
                q.push({x, y});
            }
        }
    }
    
    string ans = "";
    
    while (k > 0) {
        bool moved = false;
        for (int i = 0; i < 4; i++) {
            int x = sx + dx[i];
            int y = sy + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m) {
                continue;
            }
            if (d[x][y] <= k - 1) {
                moved = true;
                sx = x;
                sy = y;
                ans.push_back(dc[i]);
                break;
            }
        }
        if (!moved) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        k--;
    }
    
    cout << ans;
    

    return 0;
}