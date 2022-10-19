#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int MAXK = 1 << 21;
const int SQRT = 320;

int N, M, K;
int a[MAXN];
int l[MAXN], r[MAXN];
vector <int> E[SQRT];
int occ[MAXK];
ll sol[MAXN];
ll curr;

void load() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
    for (int i = 0; i < M; i++)
        scanf("%d%d", l + i, r + i);          
}

bool cmp(const int &x, const int &y) {
    if (r[x] != r[y]) return r[x] < r[y];
    return x < y;
}

void rev(int lo, int hi) {
    for (int i = hi; i >= lo; i--) {
        curr += (ll)occ[a[i] ^ K];
        occ[a[i]]++;
    }
}

void add(int lo, int hi) {
    for (int i = lo; i <= hi; i++) {
        curr += (ll)occ[a[i] ^ K];
        occ[a[i]]++;
    }
}

void remove(int lo, int hi) {
    for (int i = lo; i <= hi; i++) {
        occ[a[i]]--;
        curr -= (ll)occ[a[i] ^ K];
    }
}

void brute(int idx) {
    for (int i = l[idx]; i <= r[idx]; i++) {
        sol[idx] += (ll)occ[a[i] ^ K];
        occ[a[i]]++;
    }
    for (int i = l[idx]; i <= r[idx]; i++)
        occ[a[i]]--;
}

void solve() {
    for (int i = 1; i <= N; i++)
        a[i] ^= a[i - 1];
    
    for (int i = 0; i < M; i++) {
        l[i]--;
        if (r[i] - l[i] < SQRT - 1) brute(i); 
        else E[l[i] / SQRT].push_back(i);
    }
    
    for (int i = 0; i < SQRT; i++) {
        if (E[i].empty()) continue;
        sort(E[i].begin(), E[i].end(), cmp);
        curr = 0;
        add(l[E[i][0]], r[E[i][0]]);
        sol[E[i][0]] = curr;
        for (int j = 1; j < E[i].size(); j++) {
            int tmp = E[i][j];
            int prev = E[i][j - 1];
            if (l[tmp] < l[prev]) rev(l[tmp], l[prev] - 1);
            if (l[tmp] > l[prev]) remove(l[prev], l[tmp] - 1);
            if (r[prev] < r[tmp]) add(r[prev] + 1, r[tmp]);
            sol[tmp] = curr;
        }
        int last = E[i].back();
        remove(l[last], r[last]);
    }
        
    for (int i = 0; i < M; i++) 
        printf("%I64d\n", sol[i]);
}

int main() {
    load();
    solve();
    return 0;
}