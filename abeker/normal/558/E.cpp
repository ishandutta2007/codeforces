#include <cstdio>
using namespace std;

const int MAXN = 100005;
const int offset = 1 << 17;

struct node {
    int sum, set;
    node(int sum, int set) : sum(sum), set(set) {}
    node() : sum(0), set(-1) {}
};

struct tournament {
    node t[2 * offset];
    
    void prop(int x, int sz) {
        if (t[x].set == -1) return;
        t[x].sum = sz * t[x].set;
        if (x < offset)
            t[2 * x].set = t[2 * x + 1].set = t[x].set;
        t[x].set = -1;
    }
    
    node merge(node L, node R) {
        return node(L.sum + R.sum, L.set == R.set ? L.set : -1);
    }
    
    void update(int x, int lo, int hi, int from, int to, int val) {
        prop(x, hi - lo);
        if (lo >= to || hi <= from) return;
        if (lo >= from && hi <= to) {
            t[x].sum = (hi - lo) * val;
            if (x < offset) 
                t[2 * x].set = t[2 * x + 1].set = val;
            return;
        }
        int mid = (lo + hi) / 2;
        update(2 * x, lo, mid, from, to, val);
        update(2 * x + 1, mid, hi, from, to, val);
        t[x] = merge(t[2 * x], t[2 * x + 1]);
    }
        
    void update(int from, int to, int val) {
        update(1, 0, offset, from, to, val);
    }
    
    int query(int x, int lo, int hi, int from, int to) {
        prop(x, hi - lo);
        if (lo >= to || hi <= from) return 0;
        if (lo >= from && hi <= to) return t[x].sum;
        int mid = (lo + hi) / 2;
        return query(2 * x, lo, mid, from, to) + query(2 * x + 1, mid, hi, from, to);
    }
    
    int query(int from, int to) {
        return query(1, 0, offset, from, to);
    }
};

int N, Q;
char s[MAXN];
tournament T[30];
    
void load() {
    scanf("%d%d%s", &N, &Q, s + 1);
}

void output() {
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 26; j++)
            if (T[j].query(i, i + 1)) printf("%c", 'a' + j);
    puts("");
}

void solve() {
    for (int i = 1; i <= N; i++)
        T[s[i] - 'a'].update(i, i + 1, 1);
                   
    while (Q--) {
        int lo, hi, k;
        scanf("%d%d%d", &lo, &hi, &k);
        if (k) {
            int pos = lo;
            for (int i = 0; i < 26; i++) {
                int occ = T[i].query(lo, hi + 1);
                T[i].update(lo, hi + 1, 0);
                T[i].update(pos, pos + occ, 1);
                pos += occ;
            }
        }
        else {
            int pos = lo;
            for (int i = 25; i >= 0; i--) {
                int occ = T[i].query(lo, hi + 1);
                T[i].update(lo, hi + 1, 0);
                T[i].update(pos, pos + occ, 1);
                pos += occ;
            }
        }
    }
}

int main() {
    load();
    solve();
    output();
    return 0;
}