#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N;
pair <int, int> p[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d%d", &p[i].first, &p[i].second);
}

bool solve() {
    sort(p, p + N);
    int maks = 0;
    for (int i = 0; i < N; i++) {
        if (p[i].second < maks) return 1;
        maks = max(maks, p[i].second);
    }
    return 0;
}

int main() {
    load();
    puts(solve() ? "Happy Alex" : "Poor Alex");
    return 0;
}