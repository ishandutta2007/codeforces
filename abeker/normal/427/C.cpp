#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int N, M, sz;
int a[MAXN];
vector <int> v[MAXN];
int idx[MAXN], low[MAXN];
bool on[MAXN];
stack <int> S;
ll sum = 0, ways = 1;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);
    scanf("%d", &M);
    while (M--) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[--x].push_back(--y);
    }
}

void tarjan(int x) {
    //printf("X %d\n", x);
    idx[x] = sz;
    low[x] = sz++;
    S.push(x);
    on[x] = true;  
    for (vector <int> :: iterator it = v[x].begin(); it != v[x].end(); it++)  
        if (idx[*it] == -1) {
            tarjan(*it);
            low[x] = min(low[x], low[*it]);
        }
        else if (on[*it]) low[x] = min(low[x], idx[*it]);
    if (low[x] != idx[x]) return;
    int mini = INF, cnt = 0, curr = -1;
    for (; !S.empty() && curr != x; S.pop()) {
        curr = S.top();
        on[curr] = false;
        if (a[curr] <= mini) {
            if (a[curr] < mini) cnt = 0;
            mini = a[curr];
            cnt++;
        }
        //printf("%d ", curr);
    }    
    //puts("");
    sum += (ll)mini;
    ways = ways * (ll)cnt % MOD;
}

void solve() {
    memset(idx, -1, sizeof idx);
    for (int i = 0; i < N; i++) 
        if (idx[i] == -1) tarjan(i);
    cout << sum << ' ' << ways << endl;
}

int main() {
    load();
    solve();
    return 0;
}