#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
const int maxn = 800800;

typedef vector<int> vi;
#define pb push_back

int t[maxn][26];
vi words[maxn];
int sz = 2;
vector<pair<int, int> > res;
int total;

void add(int v, const char* s, int id) {
    while (*s) {
        int c = *s - 'a';
        if (!t[v][c]) t[v][c] = sz++;
        v = t[v][c];
        ++s;
    }
    words[v].push_back(id);
}

void gen() {
    freopen("input.txt", "w", stdout);
    int n = 100000;
    printf("%d\n", n);
    forn(i, 2*n) {
        forn(c, 4) printf("%c", 'a'+rand()%26);
        printf("\n");
    }
    exit(0);
}

void merge(vi*& a, vi *& b) {
    if (a->size() < b->size()) swap(a, b);
    a->insert(a->end(), b->begin(), b->end());
    delete b;
}

vi* dfs(int v, int h) {
    vi *b = new vi, *w = new vi;
    for (auto x: words[v]) {
        if (x < 0) b->push_back(x);
        else w->push_back(x);
    }
    forn(i, 26) if (t[v][i]) {
        vi* ch = dfs(t[v][i], h+1);
        if (!ch->empty()) {
            if (ch->front() < 0) merge(b, ch);
            else merge(w, ch);
        } else {
            delete ch;
        }
    }
    size_t mn = min(b->size(), w->size());
    forn(i, mn) {
        int x = b->back(), y = w->back();
        res.pb(make_pair(y, ~x));
        b->pop_back();
        w->pop_back();
        total += h;
    }
    if (b->empty()) { delete b; return w; }
    else { delete w; return b; }
}

char buf[maxn];
void scan() {
    int n;
    scanf("%d", &n);
    forn(K, 2) {
        forn(i, n) {
            scanf("%s", buf);
            add(1, buf, K ? i : ~i);
        }
    }
    dfs(1, 0);
    printf("%d\n", total);
    for (auto kv: res) {
        printf("%d %d\n", kv.second + 1, kv.first + 1);
    }
}

int main() {
    //gen();
#ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scan();

    return 0;
}