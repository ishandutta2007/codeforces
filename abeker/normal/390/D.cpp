#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> cell;

int N, M, K;
vector <cell> V;

void load() {
    scanf("%d%d%d", &N, &M, &K);
}

bool cmp(const cell &A, const cell &B) {
    if (A.first + A.second != B.first + B.second) 
        return A.first + A.second < B.first + B.second;
    return A.first < B.first;
}

void output(int x, int y) {
    for (int i = 0; i <= x; i++)
        printf("(%d, %d) ", i + 1, 1);
    for (int i = 1; i <= y; i++)
        printf("(%d, %d) ", x + 1, i + 1);
    puts("");
}

void solve() {
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++)
            V.push_back(cell(i, j));
    sort(V.begin(), V.end(), cmp);
    int sol = 0;
    for (int i = K - 1; i >= 0; i--)
        sol += V[i].first + V[i].second + 1;
    printf("%d\n", sol);
    for (int i = K - 1; i >= 0; i--)
        output(V[i].first, V[i].second);    
}

int main() {
    load();
    solve();
    return 0;
}