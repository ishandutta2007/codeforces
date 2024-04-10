#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl

typedef long long ll;

typedef pair <ll, int> par;

const int MAXN = 100005;
const int TOUR = 1 << 20;
const ll INF = 2 * (ll)1e15;

int N;
ll h[MAXN], D;

void dbg() { printf("KAZI DIDO JA TEBE VOLIM\n"); }

void load() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) 
        cin >> h[i];
}

int pos[MAXN];

int prev[MAXN];
int sol[MAXN];

int t[TOUR];
int offset;

inline int better(const int &x, const int &y) { return sol[x] > sol[y] ? x : y; }

void update(int x) {
    t[x + offset] = x;
    x += offset;
    for (x /= 2; x; x /= 2) 
        t[x] = better(t[2 * x], t[2 * x + 1]);
}

int get(int x, int lo, int hi, int from, int to) {
    //printf("%d %d %d %d %d\n", x, lo, hi, from, to);
    if (lo >= from && hi <= to) return t[x];
    if (lo >= to || hi <= from) return N;
    int a = get(2 * x, lo, (lo + hi) / 2, from, to);
    int b = get(2 * x + 1, (lo + hi) / 2, hi, from, to);
    return better(a, b);
}

par p[MAXN];
vector <ll> memo;

int query(ll l, ll r) {
    vector <ll> :: iterator lo, hi;
    lo = upper_bound(memo.begin(), memo.end(), l);
    hi = lower_bound(memo.begin(), memo.end(), r);
    //dbg();
    int a = get(1, 0, offset, 0, lo - memo.begin() - 1);
    int b = get(1, 0, offset, hi - memo.begin() - 1, N);
    //if (l == 4 && r == 10) TRACE(hi - memo.begin());
    //dbg();
    return better(a, b);
}

void rec(int x) {
    if (prev[x] < N) rec(prev[x]);
    printf("%d ", p[x].second + 1);
}

void solve() {
    
    memo.push_back(-INF);
    memo.push_back( INF);
    for (int i = 0; i < N; i++) { 
        p[i] = par(h[i], i);
        memo.push_back(h[i]);
    }
    sort(p, p + N);
    sort(memo.begin(), memo.end());
    for (int i = 0; i < N; i++) 
        pos[p[i].second] = i;
    
    //for (int i = 0; i < N; i++) 
    //    printf("%d ", pos[i]);
    //puts("");
    pos[N] = N;
    
    for (offset = 1; offset < N; offset *= 2);
    for (int i = 0; i < 2 * offset; i++) 
        t[i] = N;
    
    //dbg();
    int best = N;
    for (int i = 0; i < N; i++) {
        prev[pos[i]] = query(h[i] - D, h[i] + D);
        //dbg();
        //if (i == 1) TRACE(prev[pos[i]]);
        sol[pos[i]] = sol[prev[pos[i]]] + 1;
        update(pos[i]);
        best = better(best, pos[i]);
        //TRACE(sol[pos[i]]);
    }
    //dbg();
    
    //TRACE(best);
    
    printf("%d\n", sol[best]);
    rec(best);
    puts("");
    
    //for (int i = 0; i < memo.size(); i++)
    //    TRACE(memo[i]);
}

int main() {
    ios::sync_with_stdio(0);
    load();
    solve();
    return 0;
}