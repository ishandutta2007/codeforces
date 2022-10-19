#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 150005;

int N;
int t[MAXN];
bool bad[MAXN];
int cnt;

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", t + i); 
}

bool ok(int x) {
    if (x == 0 || x == N) return true;
    if (x % 2) return t[x] < t[x + 1];
    return t[x] > t[x + 1];
}

bool check() {
    for (int i = 1; i < N; i++) 
        if (!ok(i)) return false;
    return true;
}

int go(int x) {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        if (i == x) continue;
        int tmp = cnt;
        if (i != x + 1) tmp -= !ok(i - 1);
        tmp -= !ok(i);
        if (i != x - 1) tmp -= !ok(x - 1);
        tmp -= !ok(x);
        swap(t[i], t[x]);
        if (i != x + 1) tmp += !ok(i - 1);
        tmp += !ok(i);
        if (i != x - 1) tmp += !ok(x - 1);
        tmp += !ok(x);
        swap(t[i], t[x]);
        res += !tmp;
    }
    return res;
}

int solve() {
    for (int i = 1; i < N; i++) {
        bad[i] = !ok(i);
        cnt += bad[i];
    }
    
    int mini = N, maks = 0;
    for (int i = 1; i < N; i++) {
        if (!bad[i]) continue;
        mini = min(mini, i);
        maks = max(maks, i);
    }
    int diff = maks - mini;
    
    int sol = 0;
    if (diff == 0) {
        sol = go(mini) + go(mini + 1);
        swap(t[mini], t[mini + 1]);
        sol -= check();
        return sol;
    }
    
    if (diff == 1) {
        sol = go(maks);
        swap(t[mini], t[maks + 1]);
        sol += check();
        return sol;
    }
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            swap(t[mini + i], t[maks + j]);
            sol += check();
            swap(t[mini + i], t[maks + j]);
        }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}