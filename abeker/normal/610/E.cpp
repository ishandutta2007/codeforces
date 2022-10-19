#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 200005;
const int offset = 1 << 18;
const int MAXK = 11;

struct node {
    int cnt[MAXK][MAXK];
    int first, last, lazy;
    node() {
        first = last = lazy = -1;
        memset(cnt, 0, sizeof cnt);
    }
};

int N, M, K;
char s[MAXN];
node t[2 * offset];

void load() {
    scanf("%d%d%d%s", &N, &M, &K, s);
}

node merge(node L, node R) {
    node res;
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            res.cnt[i][j] += L.cnt[i][j] + R.cnt[i][j];
    if (L.last != -1 && R.first != -1)
        res.cnt[L.last][R.first]++;
    res.first = L.first;
    res.last = R.last;
    return res;
}
    
void prop(int x, int len) {
    if (t[x].lazy == -1) return;
    memset(t[x].cnt, 0, sizeof t[x].cnt);
    t[x].cnt[t[x].lazy][t[x].lazy] = len - 1;
    t[x].first = t[x].last = t[x].lazy;
    if (x < offset) 
        t[2 * x].lazy = t[2 * x + 1].lazy = t[x].lazy;
    t[x].lazy = -1;
}
    
void update(int x, int lo, int hi, int from, int to, int val) {
    prop(x, hi - lo);
    if (lo >= to || hi <= from) return;
    if (lo >= from && hi <= to) {
        memset(t[x].cnt, 0, sizeof t[x].cnt);
        t[x].cnt[val][val] = hi - lo - 1;
        t[x].first = t[x].last = val;
        if (x < offset)
            t[2 * x].lazy = t[2 * x + 1].lazy = val;
        return;
    }
    int mid = (lo + hi) / 2;
    update(2 * x, lo, mid, from, to, val);
    update(2 * x + 1, mid, hi, from, to, val);
    t[x] = merge(t[2 * x], t[2 * x + 1]);
}

void solve() {
    for (int i = 0; i < N; i++) 
        t[i + offset].first = t[i + offset].last = s[i] - 'a';
    for (int i = offset - 1; i >= 0; i--)
        t[i] = merge(t[2 * i], t[2 * i + 1]);
        
    while (M--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int l, r;
            char c;
            scanf("%d%d %c", &l, &r, &c);
            update(1, 0, offset, --l, r, c - 'a');
        }
        else {
            char buff[MAXK];
            scanf("%s", buff);
            int sol = 1;
            for (int i = 0; i < K; i++)
                for (int j = i; j < K; j++)
                    sol += t[1].cnt[buff[j] - 'a'][buff[i] - 'a'];
            printf("%d\n", sol);
        }
    }
}

int main() {
    load();
    solve();
    return 0;
}