#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector> 
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;
const int INF = INT_MAX;

int E, S, N, M;
int f[MAXN];
vector <pii> stat;
int prev[MAXN];
int suff[MAXN], sum[MAXN];
vector <int> V;

void load() {
    scanf("%d%d%d%d", &E, &S, &N, &M);
    while (N--) {
        int t, x;
        scanf("%d%d", &t, &x);
        if (x < E) stat.push_back(pii(x, t));
    }
    for (int i = 0; i < M; i++)
        scanf("%d", f + i);
}

int get(int x) {
    return lower_bound(stat.begin(), stat.end(), pii(x, 0)) - stat.begin();
}

void solve() {
    N = stat.size();
    sort(stat.begin(), stat.end());
    stat.push_back(pii(E, 0));
    int last = -INF;
    for (int i = 0; i < N; i++) 
        if (stat[i].second > 1) 
            last = stat[i].first;
        else {
            int dist = stat[i + 1].first - stat[i].first; 
            suff[i] = last == -INF ? dist : min(max(stat[i + 1].first - last - S, 0), dist);
            prev[i] = last;
        }
        
    for (int i = N - 1; i >= 0; i--)
        suff[i] += suff[i + 1];
    
    last = E;
    for (int i = N - 1; i >= 0; i--) {
        sum[i] = sum[i + 1];
        if (stat[i].second < 3) continue;
        sum[i] += min(last - stat[i].first, S);
        last = stat[i].first;
    }
    
    int pos = -1;
    for (int i = 0; i < N; i++)
        if (stat[i + 1].first - stat[i].first > S)  
            pos = i;
        
    for (int i = 0; i < N; i++)
        if (stat[i].second == 3) 
            V.push_back(stat[i].first);
    V.push_back(INF);
    
    for (int i = 0; i < M; i++) {
        if (f[i] + S >= E) {
            puts("0 0");
            continue;
        }
        int idx1 = get(f[i] + 1);
        int idx2 = get(f[i] + S + 1);
        int idx3 = upper_bound(stat.begin(), stat.end(), pii(f[i] + S, 4)) - stat.begin() - 1;
        if (idx1 <= pos || stat[idx1].first - f[i] > S) {
            puts("-1 -1");
            continue;
        }
        int curr = *lower_bound(V.begin(), V.end(), f[i] + 1);
        int rest = E - f[i] - sum[idx1] - (curr == INF ? S : min(curr - f[i], S));
        int prem = suff[idx2];
        if (stat[idx3].second == 1) {
            int tmp = max(f[i], prev[idx3]);
            prem += max(stat[idx3 + 1].first - tmp - S, 0);
        }
        printf("%d %d\n", prem, rest - prem);
    }
    
}

int main() {
    load();
    solve();
    return 0;
}