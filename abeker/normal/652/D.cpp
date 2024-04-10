#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;

int N;
pii p[MAXN], t[MAXN];
int f[MAXN];
map <pii, int> sol;
vector <int> V;

void update(int x) {
    for (; x < MAXN; x += x & -x)
        f[x]++;
}

int get(int x) {
    int ret = 0;
    for (; x; x -= x & -x)
        ret += f[x];
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &p[i].second, &p[i].first);
        t[i] = p[i];
        V.push_back(p[i].second);
    }
    
    sort(V.begin(), V.end());
    sort(t, t + N);
    for (int i = 0; i < N; i++) {
        int curr = lower_bound(V.begin(), V.end(), t[i].second) - V.begin() + 1;
        sol[t[i]] = i - get(curr);
        update(curr);
    }
    
    for (int i = 0; i < N; i++)
        printf("%d\n", sol[p[i]]);
        
    return 0;
}