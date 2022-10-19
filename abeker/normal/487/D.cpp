#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;
const int MAXM = 15;
const int offset = 1 << 17;

struct node {
    int l, r;
    pii where[MAXM];
    node() {
        l = r = -1;
        for (int i = 0; i < MAXM; i++)
            where[i] = pii(0, 0);
    }
};
 
int N, M, Q;
char mat[MAXN][MAXM];
node t[2 * offset];

node merge(node L, node R) {
    node res;
    for (int i = 1; i <= M; i++) {
        pii &ref = res.where[i];
        ref = R.where[i];
        if (ref.first > 0 && ref.first < R.l)   
            ref = L.where[ref.second];
    }
    res.l = L.l;
    res.r = R.r;
    if (L.l == -1) res = R;
    if (R.l == -1) res = L;
    return res;
}

pii get(int x, int y) {
    while (y > 0 && y <= M) {
        if (mat[x][y] == '<') {
            if (y > 1 && mat[x][y - 1] == '>') 
                return pii(-1, -1);
            y--;
        }
        if (mat[x][y] == '>') {
            if (y < M && mat[x][y + 1] == '<') 
                return pii(-1, -1);
            y++; 
        }
        if (mat[x][y] == '^') 
            return pii(x - 1, y);
    }
    return pii(x, y);
}

void update(int x) {
    int pos = x + offset;
    for (int i = 1; i <= M; i++) 
        t[pos].where[i] = get(x, i);
    t[pos].l = x;
    t[pos].r = x + 1;
    for (pos /= 2; pos; pos /= 2)
        t[pos] = merge(t[2 * pos], t[2 * pos + 1]);
}

node query(int x, int lo, int hi, int from, int to) {
    if (lo >= to || hi <= from) return node();
    if (lo >= from && hi <= to) return t[x]; 
    int mid = (lo + hi) / 2;
    return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void load() {
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 1; i <= N; i++)
        scanf("%s", mat[i] + 1);
}

void solve() {
    for (int i = 1; i <= N; i++)
        update(i);
    
    scanf("%d", &Q);
    while (Q--) {
        char cmd;
        int x, y;
        scanf(" %c%d%d", &cmd, &x, &y);
        if (cmd == 'A') {
            pii ans = query(1, 0, offset, 0, x + 1).where[y];
            printf("%d %d\n", ans.first, ans.second);
        }
        else {
            char ch;
            scanf(" %c", &ch);
            mat[x][y] = ch;
            update(x);
        }
    }
}

int main() {
    load();
    solve();
    return 0;
}