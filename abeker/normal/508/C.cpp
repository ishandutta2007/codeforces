#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 305;

int M, T, R;
int w[MAXN];

void load() {
    scanf("%d%d%d", &M, &T, &R);
    for (int i = 0; i < M; i++) 
        scanf("%d", w + i);
}

int solve() {
    if (R > T) return -1;
    vector <int> V;
    for (int i = 0; i < M; i++) {
        int cnt = 0;
        for (int j = 0; j < V.size(); j++) 
            if (V[j] + T > w[i]) cnt++;
        for (int j = 0; j < R - cnt; j++) 
            V.push_back(w[i] - j);
    }
    return (int)V.size();
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}