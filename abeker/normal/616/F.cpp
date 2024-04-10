#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;
const int MAXM = 500005;
const int LOG = 20;

int N;
int c[MAXN];
string t[MAXN];
char buff[MAXM];
vector <pii> V;
int suff[MAXM];
int rank[LOG][MAXM];
int dad[MAXM];
ll sum[MAXM];
vector <int> E[MAXM], Q[MAXM];
multiset <ll> S;
int it;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", buff);
        t[i] = buff;
    }
    for (int i = 0; i < N; i++)
        scanf("%d", c + i); 
}

int lcp(int x, int y) {
    int ret = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        if (V[x].second + ret + (1 << i) > t[V[x].first].size() || V[y].second + ret + (1 << i) > t[V[y].first].size()) continue;
        if (rank[i][x + ret] == rank[i][y + ret]) ret += 1 << i;
    }
    return ret;
}

bool cmp(int x, int y) {
    if (!it) return t[V[x].first][V[x].second] < t[V[y].first][V[y].second];
    if (rank[it - 1][x] != rank[it - 1][y])
        return rank[it - 1][x] < rank[it - 1][y];
    if (V[y].second + (1 << it - 1) >= t[V[y].first].size()) return 0;
    if (V[x].second + (1 << it - 1) >= t[V[x].first].size()) return 1;
    return rank[it - 1][x + (1 << it - 1)] < rank[it - 1][y + (1 << it - 1)];
}

int find(int x) {
    return x == dad[x] ? x : dad[x] = find(dad[x]);
}

void join(int x) {
    int y = x - 1;
    if (rand() % 2) swap(x, y);
    x = find(x);
    y = find(y);
    S.erase(S.find(sum[x]));
    S.erase(S.find(sum[y]));
    sum[y] += sum[x];
    dad[x] = y;
    S.insert(sum[y]);
}

ll solve() {
    int M = 0;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < t[i].size(); j++) {
            suff[M] = M; M++;
            V.push_back(pii(i, j));
        }
    
    for (it = 0; it < LOG; it++) {
        sort(suff, suff + M, cmp);   
        for (int i = 1; i < M; i++)
            rank[it][suff[i]] = rank[it][suff[i - 1]] + cmp(suff[i - 1], suff[i]);
    }
    
    for (int i = 0; i < M; i++) {
        pii tmp = V[suff[i]];
        if (i) E[lcp(suff[i - 1], suff[i])].push_back(i);
        dad[i] = i;
        sum[i] = (ll)c[tmp.first];
        Q[t[tmp.first].size() - tmp.second].push_back(i);
    }
    
    ll sol = 0;
    for (int i = MAXM - 1; i >= 0; i--) {
        for (int j = 0; j < Q[i].size(); j++)
            S.insert(sum[Q[i][j]]);
        for (int j = 0; j < E[i].size(); j++) 
            join(E[i][j]);
        if (!S.empty()) sol = max(sol, (ll)*S.rbegin() * i);
    }
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}