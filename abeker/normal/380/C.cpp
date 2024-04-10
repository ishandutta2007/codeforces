#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1000005;

int N, M;
int l[MAXN], r[MAXN];
char s[MAXN];
vector <int> Q[MAXN];
int last[2 * MAXN], add[2 * MAXN];
int f[MAXN];
int pref[MAXN];
int sol[MAXN];

void load() {
    scanf("%s%d", s + 1, &M);
    for (int i = 0; i < M; i++)
        scanf("%d%d", l + i, r + i);
}

void update(int x, int val) {
    for (x++; x < MAXN; x += x & -x)
        f[x] += val;
}

int get(int x) {
    int ret = 0;
    for (x++; x; x -= x & -x)
        ret += f[x];
    return ret;
}

void solve() {
    N = strlen(s + 1);
    for (int i = 0; i < M; i++) 
        Q[r[i]].push_back(i);
        
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i - 1] + (s[i] == '(');
          
    int sum = MAXN;
    for (int i = 1; i <= N; i++) {
        if (s[i] == '(') {
            update(last[sum], -add[sum]);
            add[sum] = 1;
            last[sum] = i;
            update(last[sum], add[sum]);
            sum++;
        }
        else {
            sum--;
            update(last[sum], -add[sum]);
            add[sum] = 0;
            last[sum] = i;
            update(last[sum], add[sum]);
        }
        for (int j = 0; j < Q[i].size(); j++) 
            sol[Q[i][j]] = pref[i] - pref[l[Q[i][j]] - 1] - get(i) + get(l[Q[i][j]] - 1);
    }
    
    for (int i = 0; i < M; i++)
        printf("%d\n", 2 * sol[i]);
}

int main() {
    load();
    solve();
    return 0;
}