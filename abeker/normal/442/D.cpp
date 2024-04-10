#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1000005;

int N;
int dad[MAXN];
int ch[MAXN];
int mx1[MAXN], mx2[MAXN];
int sol = 1;

void recalc(int x) {
    mx1[x] = 1;
    int val = 1;
    for (; dad[x] > 1; x = dad[x]) {
        int p = dad[x];
        int old = max(mx1[p], mx2[p] + 1);
        if (ch[p] > 1) {
            if (val >= mx1[p]) {
                mx2[p] = mx1[p];
                mx1[p] = val;
            }
            else if (val > mx2[p]) 
                mx2[p] = val;
        }
        else mx1[p] = val;
        int nxt = max(mx1[p], mx2[p] + 1);
        if (nxt == old) break;
        sol = max(sol, nxt);
        val = nxt;
    }
}

int main() {
    scanf("%d", &N);
    mx1[1] = 1;
    for (int i = 1; i <= N; i++) {
        int p;
        scanf("%d", &p);
        dad[i + 1] = p;
        ch[p]++;
        recalc(i + 1);
        printf("%d ", sol);
    }
    puts("");
    return 0;
}