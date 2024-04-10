#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int MAXN = 200005;
const int offset = 1 << 18;

int N;
int a[MAXN], b[MAXN];
int c[MAXN], d[MAXN];
vector <int> V;
queue <int> Q;
int dist[MAXN];
int dad[MAXN];

struct cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (b[lhs] != b[rhs]) return b[lhs] < b[rhs];
        return lhs < rhs;
    }
};

set <int, cmp> S[2 * offset];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
}

void update(int x) {
    for (int pos = a[x] + offset; pos; pos /= 2)
        S[pos].erase(x);
}

void query(int x, int lo, int hi, int from, int to, int node) {
    if (lo >= to || hi <= from) return;
    if (lo >= from && hi <= to) {
        vector <int> tmp;
        if (S[x].empty()) return;
        for (set <int, cmp> :: iterator it = S[x].begin(); it != S[x].end() && b[*it] <= d[node]; it++) 
            tmp.push_back(*it);
        for (int i = 0; i < tmp.size(); i++) {
            int curr = tmp[i];
            Q.push(curr);
            dist[curr] = dist[node] + 1;
            dad[curr] = node;
            update(curr);
        }
        return;
    }
    int mid = (lo + hi) / 2;
    query(2 * x, lo, mid, from, to, node);
    query(2 * x + 1, mid, hi, from, to, node);
}

void add(set <int, cmp> from, set <int, cmp> &to) {
    for (set <int, cmp> :: iterator it = from.begin(); it != from.end(); it++)
        to.insert(*it);
}

void solve() {
    for (int i = 0; i <= N; i++) {
        V.push_back(a[i]);
        V.push_back(c[i]);
    } 
    sort(V.begin(), V.end());
    
    for (int i = 0; i <= N; i++) {
        a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin();
        c[i] = lower_bound(V.begin(), V.end(), c[i]) - V.begin();
    }
    
    for (int i = 0; i <= N; i++) 
        S[a[i] + offset].insert(i);
    
    for (int i = offset - 1; i >= 0; i--) {
        add(S[2 * i], S[i]);
        add(S[2 * i + 1], S[i]);
    }
    
    memset(dist, -1, sizeof dist);
    dist[N] = 0;
    Q.push(N);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        query(1, 0, offset, 0, c[x] + 1, x);
    }
    
    printf("%d\n", dist[N - 1]);
    
    if (dist[N - 1] == -1) return;
    
    vector <int> path;
    for (int x = N - 1; x != N; x = dad[x])
        path.push_back(x);
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
        printf("%d ", ++path[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}