#include <cstdio>
#include <cstring>
using namespace std;

const int offset = 1 << 17;
const int MAXT = 60;

struct tournament {
    int curr;
    int t[2 * offset][MAXT];
    
    int merge(int Time, int idx, int rem) {
        return Time + t[idx][(Time + rem) % MAXT];
    }
    
    tournament() {
        memset(t, 0, sizeof t);
    }
    
    void update(int pos, int val) {
        pos += offset;
        for (int i = 0; i < MAXT; i++)
            t[pos][i] = 1 + !(i % val);
        for (pos /= 2; pos; pos /= 2) 
            for (int i = 0; i < MAXT; i++) 
                t[pos][i] = merge(t[2 * pos][i], 2 * pos + 1, i);
    }
    
    void go(int x, int lo, int hi, int from, int to) {
        if (hi <= from || lo >= to) return;
        if (lo >= from && hi <= to) {
            curr = merge(curr, x, 0);
            return;
        }
        int mid = (lo + hi) / 2;
        go(2 * x, lo, mid, from, to);   
        go(2 * x + 1, mid, hi, from, to);
    }
    
    int query(int from, int to) {
        curr = 0;
        go(1, 0, offset, from, to); 
        return curr;
    }
} T;

int N, Q;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a; scanf("%d", &a);
        T.update(i, a);
    }
}

void solve() {
    scanf("%d", &Q);
    while (Q--) {
        char cmd;
        int x, y;
        scanf(" %c%d%d", &cmd, &x, &y); x--;
        if (cmd == 'A') printf("%d\n", T.query(x, --y));
        else T.update(x, y);
    }
}

int main() {
    load();
    solve();
    return 0;
}