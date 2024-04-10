#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 400005;

struct fenwick {
    int pref[2 * MAXN];
    int suff[2 * MAXN];
    fenwick() {
        memset(pref, 0, sizeof pref);
        memset(suff, 0, sizeof suff);
    }
    void update_pref(int x, int val) {
        for (x++; x < 2 * MAXN; x += x & -x)
            pref[x] = max(pref[x], val);
    }
    int get_pref(int x) {
        int ret = 0;
        for (x++; x; x -= x & -x)
            ret = max(ret, pref[x]);
        return ret;
    }
    void update_suff(int x, int val) {
        for (x = 2 * MAXN - x - 1; x < 2 * MAXN; x += x & -x)
            suff[x] = max(suff[x], val);
    }
    int get_suff(int x) {
        int ret = 0;
        for (x = 2 * MAXN - x - 1; x; x -= x & -x)
            ret = max(ret, suff[x]);
        return ret;
    }
};

int N, M;
int h[MAXN];
int a[MAXN], b[MAXN];
int left[MAXN], right[MAXN];
vector <int> V;
fenwick F;
int cnt[MAXN];
bool in_all[MAXN];
vector <int> Q[MAXN];
int query_left[MAXN], query_right[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", h + i);
    for (int i = 0; i < M; i++)
        scanf("%d%d", a + i, b + i);
}

void compress(int &ref) {
    ref = lower_bound(V.begin(), V.end(), ref) - V.begin();
}

void solve() {
    for (int i = 0; i < N; i++)
        V.push_back(h[i]);
    for (int i = 0; i < M; i++) {
        V.push_back(b[i]);
        Q[--a[i]].push_back(i);
    }
    
    sort(V.begin(), V.end());
    for (int i = 0; i < N; i++)
        compress(h[i]);
    for (int i = 0; i < M; i++)
        compress(b[i]);
        
    for (int i = 0; i < N; i++) {
        left[i] = F.get_pref(h[i] - 1) + 1;
        for (int j = 0; j < Q[i].size(); j++)
            query_left[Q[i][j]] = F.get_pref(b[Q[i][j]] - 1);
        F.update_pref(h[i], left[i]);
    }
    
    for (int i = N - 1; i >= 0; i--) {
        right[i] = F.get_suff(h[i] + 1) + 1;
        for (int j = 0; j < Q[i].size(); j++)
            query_right[Q[i][j]] = F.get_suff(b[Q[i][j]] + 1);
        F.update_suff(h[i], right[i]);
    }
    
    int lis = *max_element(left, left + N);
    for (int i = 0; i < N; i++)
        if (left[i] + right[i] - 1 == lis) 
            cnt[left[i]]++;
    
    for (int i = 0; i < N; i++)
        in_all[i] = left[i] + right[i] - 1 == lis && cnt[left[i]] == 1;
    
    for (int i = 0; i < M; i++) 
        printf("%d\n", max(query_left[i] + query_right[i] + 1, in_all[a[i]] ? lis - 1: lis));
}

int main() {
    load();
    solve();
    return 0;
}