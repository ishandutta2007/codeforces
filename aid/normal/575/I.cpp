#include <iostream>

using namespace std;

const int MAXN = 5005;
int *fen[3][MAXN], sz[] = {MAXN, 2 * MAXN, 2 * MAXN};

void add(int t, int x, int y, int val) {
    int yy = y;
    for(; x < MAXN; x |= x + 1) {
        y = yy;
        for(; y < sz[t]; y |= y + 1)
            fen[t][x][y] += val;
    }
}

int get(int t, int x, int y) {
    int res = 0, yy = y;
    for(; x >= 0; x = (x & (x + 1)) - 1) {
        y = yy;
        for(; y >= 0; y = (y & (y + 1)) - 1)
            res += fen[t][x][y];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < MAXN; i++)
        fen[0][i] = new int[MAXN]();
    for(int i = 0; i < MAXN; i++)
        fen[1][i] = new int[2 * MAXN]();
    for(int i = 0; i < MAXN; i++)
        fen[2][i] = new int[2 * MAXN]();
    int n, q;
    cin >> n >> q;
    for(int qq = 0; qq < q; qq++) {
        int qt;
        cin >> qt;
        if(qt == 1) {
            int dir, x, y, len;
            cin >> dir >> x >> y >> len;
            x--;
            y--;
            if(dir == 1) {
                add(0, x, y, 1);
                add(0, x + len + 1, y, -1);
                add(1, x, x + y + len + 1, -1);
                add(1, x + len + 1, x + y + len + 1, 1);
            }
            else if(dir == 2) {
                add(0, x, y + 1, -1);
                add(0, x + len + 1, y + 1, 1);
                add(2, x, y + n - x - 1 - len, 1);
                add(2, x + len + 1, y + n - x - 1 - len, -1);
            }
            else if(dir == 3) {
                add(0, x - len, y, 1);
                add(0, x + 1, y, -1);
                add(2, x - len, y + n - x + len, -1);
                add(2, x + 1, y + n - x + len, 1);
            }
            else {
                add(0, x - len, y + 1, -1);
                add(0, x + 1, y + 1, 1);
                add(1, x - len, x + y - len, 1);
                add(1, x + 1, x + y - len, -1);
            }
        }
        else {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            cout << get(0, x, y) + get(1, x, x + y) + get(2, x, y + n - x - 1)
                 << '\n';
        }
    }
    return 0;
}