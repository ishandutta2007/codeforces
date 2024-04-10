#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 3005;

int N, M;
int p[MAXN];
int head[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", p + i);
    scanf("%d", &M);
}

void dfs(int x, int y) {
    if (head[x]) return;
    head[x] = y;
    dfs(p[x], y);
}

int cycles() {
    int res = 0;
    memset(head, 0, sizeof head);
    for (int i = 1; i <= N; i++)
        if (!head[i]) {
            dfs(i, i);
            res++;
        }
    return res;
}

void doit(int x, int y) {
    swap(p[x], p[y]);
    printf("%d %d ", x, y);
}

void solve() {
    M = N - M;
    int curr = cycles();
    if (curr < M) {
        printf("%d\n", M - curr);
        while (cycles() < M) {
            int pos = 0;
            for (int i = 1; i <= N; i++) 
                if (p[i] != i) { 
                    pos = i; 
                    break;
                }
            int mini = 0;
            for (int i = 1; i <= N; i++) 
                if (head[i] == head[pos] && i != pos) {
                    mini = i;
                    break;
                }
            doit(pos, mini);
        } 
    }
    else {
        printf("%d\n", curr - M);
        while (cycles() > M) {
            int pos = 0;
            for (int i = 1; i <= N; i++) 
                if (head[i] != head[1]) {
                    pos = i;
                    break;
                }
            doit(1, pos);
        }
    }
    puts("");
}

int main() {
    load(); 
    solve();
    return 0;
}