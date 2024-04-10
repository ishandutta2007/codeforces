#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#define M 200010

using namespace std;

int Head[M], Next[M], Go[M], D[M], Cnt = 0, n, m, st, flag = 0;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

vector <int> tmp, Ans;

int col[M], vis[M], can[M];

void print(vector <int> &X) {
    for(int i = 0; i < X.size(); i++) printf("%d ", X[i]);
}

int DFS1(int x, int y = 0) {
    vis[x] = 1;
    tmp.push_back(x);
    if(!D[x]) {
        can[x] = 1;
        if(y == 1) {
            puts("Win");
            print(Ans);
            print(tmp);
            exit(0);
        } else flag = 1;
    }
    for(int T = Head[x]; T; T = Next[T]) if(!vis[Go[T]]) can[x] |= DFS1(Go[T], 1 - y);
    tmp.pop_back();
    return can[x];
}

bool inq[M];

void DFS2(int x, int y = 0) {
    inq[x] = 1;
    Ans.push_back(x);
    col[x] = y;
    for(int T = Head[x]; T; T = Next[T])
        if(col[Go[T]] == -1) DFS2(Go[T], 1 - y);
        else if(inq[Go[T]]) {
            flag = 1;
            if(col[Go[T]] == y && can[Go[T]]) {
                memset(vis, 0, sizeof vis);
                DFS1(Go[T], 1 - y);
            }
        }
    Ans.pop_back();
    inq[x] = 0;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int c, x;
        scanf("%d", &c);
        D[i] = c;
        while(c--) {
            scanf("%d", &x);
            addedge(i, x);
        }
    }
    scanf("%d", &st);
    DFS1(st);
    if(!flag) {
        puts("Draw");
        return 0;
    }
    memset(col, -1, sizeof col);
    flag = 0;
    DFS2(st);
    puts(flag ? "Draw" : "Lose");
    return 0;
}