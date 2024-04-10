#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

const int MAXN = 150005;

int N;
int p[MAXN], t[MAXN];
ll mini[MAXN], maks[MAXN];
int idx[MAXN];
ll pref[MAXN];
pii task[MAXN];
ld best[MAXN];
int where[MAXN];
ll T;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", p + i);
    for (int i = 0; i < N; i++)
        scanf("%d", t + i);
}

ld eval(int init, ll x, ld c) {
    return init * (1 - c * x / T);
}

bool check(ld c) {
    for (int i = 0; i < N; i++) {
        best[i] = eval(task[i].first, mini[task[i].second], c);
        if (i) best[i] = max(best[i], best[i - 1]);
    }   
    
    for (int i = 0; i < N; i++) {
        ld tmp = eval(task[i].first, maks[task[i].second], c);
        ld cand = where[i] == -1 ? 0 : best[where[i]];
        if (tmp < cand) return false;
    }
    
    return true;
}

bool cmp(const int &l, const int &r) {
    return (ll)p[l] * t[r] > (ll)p[r] * t[l];
}

ld solve() {
    p[N] = 1;
    t[N] = (int)1e9;
    for (int i = 0; i < N; i++)
        idx[i] = i;
    sort(idx, idx + N, cmp);
    idx[N] = N;
    
    pref[0] = t[idx[0]];
    for (int i = 1; i < N; i++)
        pref[i] = pref[i - 1] + t[idx[i]];
    
    for (int i = 0; i < N; i++) {
        int pos = lower_bound(idx, idx + N, i, cmp) - idx;
        mini[i] = (pos ? pref[pos - 1] : 0) + t[i];
        pos = upper_bound(idx, idx + N, i, cmp) - idx;
        maks[i] = pref[pos - 1]; 
    }
    
    for (int i = 0; i < N; i++) {
        task[i] = pii(p[i], i);
        T += t[i];
    }
    sort(task, task + N);
    
    for (int i = 0; i < N; i++)
        where[i] = lower_bound(task, task + N, pii(task[i].first, -1)) - task - 1;
        
    ld lo = 0, hi = 1;
    for (int i = 0; i < 500; i++) {
        ld mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    
    return lo;
}

int main() {
    load();
    printf("%.11lf\n", (double)solve());
    return 0;
}