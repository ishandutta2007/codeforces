#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii; 

const int MAXN = 200005;
const int INF = 0x3f3f3f3f;

int N;
int sum[MAXN][3];
int pos[MAXN][3];
vector < pii > sol; 

void load() {
    memset(pos, INF, sizeof pos);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int who; scanf("%d", &who);
        for (int j = 1; j < 3; j++) 
            sum[i][j] = sum[i - 1][j];
        pos[++sum[i][who]][who] = i;
    }
}

int play(int t) {
    int cnt[3] = {0}, last = 0;
    for (int curr = 0; curr < N;) {
        int a = pos[sum[curr][1] + t][1];
        int b = pos[sum[curr][2] + t][2];
        curr = min(a, b);
        if (curr == INF) return -1;
        if (a < b) last = 1;
        else last = 2;
        cnt[last]++;
    }
    if (cnt[last] <= cnt[3 - last]) return -1;
    return max(cnt[1], cnt[2]);
}

void solve() {
    for (int i = 1; i <= N; i++) {
        int tmp = play(i);
        if (tmp != -1) sol.push_back(pii(tmp, i));
    }
    printf("%d\n", sol.size());
    sort(sol.begin(), sol.end());
    for (int i = 0; i < sol.size(); i++) 
        printf("%d %d\n", sol[i].first, sol[i].second);
}

int main() {
    load();
    solve();
    return 0;
}