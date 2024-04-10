#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N;
int a[MAXN];
vector <int> V;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int solve() {
    for (int i = 0; i < N; i++)
        V.push_back(a[i]);
    sort(V.begin(), V.end());
    for (int i = 0; i < N; i++)
        a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin();
    
    int maks = -1, cnt, sol = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] >= maks) {
            if (a[i] > maks) cnt = 0;
            maks = a[i];
            cnt++;
        }
        if (maks + cnt == i + 1) sol++;
    }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}