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

template <typename T>
using heap = priority_queue<T, vector<T>, std::greater<T>>;

typedef long long lint;

int n, m;
char a[1111][1111];
char b[1111][1111];
int ans = 1e9;
int w, h;
int sx, sy;

void calc_wh() {
    int x = -1, y = -1;
    for (int i = 0; x == -1 && i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X') {
                x = i;
                y = j;
                break;
            }
        }
    }
    sx = x;
    sy = y;
    w = 0;
    for (int i = y; i < m && a[x][i] == 'X'; i++) {
        w++;
    }
    
    while (x + 1 < n && a[x + 1][y] == 'X') {
        x++;
    }
    h = 0;
    while (x >= 0 && y + w < m && a[x][y + w] == 'X') {
        h++;
        x--;
    }
    if (h == 0) {
        h = 1;
    }
}

int calc_ans() {
    calc_wh();
    if (w == 0 || h == 0) {
        return 1e9;
    } 
    
    memset(b, 0, sizeof(char) * 1111 * 1111);
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            b[sx + i][sy + j] = 'X';
        }
    }
    
    int x = sx;
    int y = sy;
    
    while (true) {
        bool can_d = x + h < n && a[x + h][y] == 'X';
        bool can_r = y + w < m && a[x][y + w] == 'X';
        
        if (can_d) {
            for (int i = 0; i < w; i++) {
                b[x + h][y + i] = 'X';
            }
            x++;
        } else if (can_r) {
            for (int i = 0; i < h; i++) {
                b[x + i][y + w] = 'X';
            }
            y++;
        } else {
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((a[i][j] == 'X') != (b[i][j] == 'X')) {
                return 1e9;
            }
        }
    }

    return w * h;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    sci(n, m);
    for (int i = 0; i < n; i++) {
        scids(s);
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }
    
    ans = calc_ans();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][i] = a[i][j];
        }
    }
    swap(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
    
    ans = min(ans, calc_ans());
    
    cout << (ans == 1e9 ? -1 : ans);

    return 0;
}