#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cassert>

#define M 400010

using namespace std;

int Head[M], Next[M], Go[M], L[M], R[M], F[M], Ran[M], Size[M], Where[M], Val[M], Who[M], Min[M], Max[M], Dec[M];

int n, m, Cnt = 0, th = 0, Root = 0;

inline void Down(int x)
{
    if(!x) return;
    if(Dec[x])
    {
        if(L[x]) Dec[L[x]] += Dec[x];
        if(R[x]) Dec[R[x]] += Dec[x];
        Min[x] -= Dec[x];
        Max[x] -= Dec[x];
        Val[x] -= Dec[x];
        Dec[x] = 0;
    }
}

inline void Update(int x)
{
    Down(x);
    Down(L[x]);
    Down(R[x]);
    Size[x] = Size[L[x]] + Size[R[x]] + 1;
    Min[x] = min(Val[x], min(Min[L[x]], Min[R[x]]));
    Max[x] = max(Val[x], max(Max[L[x]], Max[R[x]]));
}

inline void addedge(int x, int y)
{
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

int Merge(int& x, int& y)
{
    if(!x) return y;
    if(!y) return x;
    if(Ran[x] < Ran[y])
    {
        Down(x);
        R[x] = Merge(R[x], y);
        F[R[x]] = x;
        Update(x);
        return x;
    }
    else
    {
        Down(y);
        L[y] = Merge(x, L[y]);
        F[L[y]] = y;
        Update(y);
        return y;
    }
}

void Cut(int now, int& x, int& y, int th)
{
    if(!Size[now])
        x = 0, y = now;
    else if(Size[now] == th)
        x = now, y = 0;
    else if(Size[L[now]] >= th)
    {
        y = now;
        Down(y);
        F[L[y]] = 0;
        Cut(L[now], x, L[y], th);
        F[L[y]] = y;
        Update(y);
    }
    else
    {
        x = now;
        Down(x);
        F[R[x]] = 0;
        Cut(R[now], R[x], y, th - Size[L[now]] - 1);
        F[R[x]] = x;
        Update(x);
    }
}

inline int newnode(int who, int x)
{
    th++;
    Ran[th] = rand();
    Val[th] = Max[th] = Min[th] = x;
    Size[th] = 1;
    L[th] = R[th] = 0;
    Who[th] = who;
    F[th] = 0;
    return th;
}

inline void Push_back(int who, int x)
{
    int tmp = newnode(who, x);
    Root = Merge(Root, tmp);
}

void dfs(int x, int dep)
{
    Push_back(x * 2, dep);
    Where[x * 2] = th;
    for(int T = Head[x]; T; T = Next[T])
        dfs(Go[T], dep + 1);
    Push_back(x * 2 + 1, dep);
    Where[x * 2 + 1] = th;
}

void Fix(int x)
{
    if(F[x]) Fix(F[x]);
    Down(x);
}

int Query_Min(int x, int y)
{
    int q = 0, p = 0;
    Cut(Root, Root, p, y);
    Cut(Root, Root, q, x - 1);
    int ans = Min[q];
    Root = Merge(Root, q);
    Root = Merge(Root, p);
    return ans;
}

int rank(int x)
{
    if(!F[x]) return 0;
    if(R[F[x]] == x) return rank(F[x]) + Size[L[F[x]]] + 1;
    else return rank(F[x]);
}

int Rank(int x)
{
    return rank(x) + Size[L[x]] + 1;
}

int Find(int now, int x)
{
    for(; ;)
    {
        Down(now);
        Down(L[now]);
        Down(R[now]);
        if(Min[R[now]] <= x && Max[R[now]] >= x) now = R[now];
        else if(Val[now] == x) return Who[now];
        else now = L[now];
    }
}

void dfs_print(int x)
{
    if(!x) return;
    Down(x);
    dfs_print(L[x]);
    printf("%d ", Val[x]);
    dfs_print(R[x]);
}

int TT[M];
int main()
{
    Min[0] = 2147483647;
    Max[0] = -2147483647;
    srand(32479823);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        int s;
        scanf("%d", &s);
        for(int j = 1; j <= s; j++) scanf("%d", &TT[j]);
        for(int j = s; j >= 1; j--) addedge(i, TT[j]);
    }
    dfs(1, 1);
    for(int i = 1; i <= m; i++)
    {
        int op, x, y;
        scanf("%d%d", &op, &x);
        if(op != 3) scanf("%d", &y);
        if(op == 1)
        {
            int xL = Where[x * 2], xR = Where[x * 2 + 1], yL = Where[y * 2], yR = Where[y * 2 + 1];
            Fix(xL), Fix(xR), Fix(yL), Fix(yR);
            if(Rank(xL) > Rank(yL)) xL ^= yL ^= xL ^= yL, xR ^= yR ^= xR ^= yR;
            if(Rank(yL) < Rank(xR)) printf("%d\n", Val[yL] - Val[xL]);
            else printf("%d\n", Val[xL] + Val[yL] - 2 * Query_Min(Rank(xL), Rank(yL)) + 2);
        }
        else if(op == 2)
        {
            int p, q, r, xL = Where[x * 2], xR = Where[x * 2 + 1];
            Fix(xL), Fix(xR);
            Cut(Root, Root, p, Rank(xL) - 1);
            int tmp = Find(Root, Val[xL] - y);
            int yL = Where[tmp], yR = Where[tmp + 1];
            Fix(yL), Fix(yR);
            Cut(p, p, q, Rank(xR));
            Cut(q, q, r, Rank(yR) - 1);
            Dec[p] += y - 1;
            Root = Merge(Root, q);
            Root = Merge(Root, p);
            Root = Merge(Root, r);
        }
        else
        {
            printf("%d\n", Find(Root, x + 1) / 2);
        }
    }
    return 0;
}