#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

#define M 1600010
#define Inf 1000000007
#define Start_node 0
#define End_node 2
#define line 1
#define lc (now * 2)
#define rc (now * 2 + 1)
#define mid (L + R >> 1)

using namespace std;

struct Line
{
    int x, y, len, id;
};

struct node
{
    int x, y, id, op;
};

Line Hang[M], Lie[M];

int CntHang = 0, CntLie = 0, Cnt = 0;

node Tmp[M];

int F[M], Tag[M], Size[M];

long long Ans[M], ans = 0;

int getfa(int x)
{
    return (F[x] == x) ? x : (F[x] = getfa(F[x]));
}

inline bool cmp2(node x, node y)
{
    return x.x < y.x || x.x == y.x && x.op < y.op || x.x == y.x && x.op == y.op && x.y < y.y;
}

inline bool cmp3(node x, node y)
{
    return x.y < y.y || x.y == y.y && x.op < y.op || x.y == y.y && x.op == y.op && x.id < y.id;
}

inline void Merge(int x, int y)
{
    if(x && y && getfa(x) != getfa(y)) F[getfa(x)] = getfa(y);
}

inline void Down(int now, int L, int R)
{
    if(Tag[now])
    {
        if(Size[lc]) Merge(Tag[lc], Tag[now]);
        if(Size[rc]) Merge(Tag[rc], Tag[now]);
        Tag[lc] = Tag[rc] = Tag[now];
        Tag[now] = 0;
    }
}

int tmp = 0;

void Insert(int now, int L, int R, int who)
{
    if(L == R)
    {
        Tag[now] = Tmp[who].id;
        Size[now] = 1;
        return;
    }
    Size[now]++;
    Down(now, L, R);
    if(Tmp[who].y <= mid) Insert(lc, L, mid, who);
    else Insert(rc, mid + 1, R, who);
}

void Delete(int now, int L, int R, int who)
{
    if(L == R)
    {
		if(Size[now]) Merge(Tag[now], Tmp[who].id);
        Size[now] = 0;
        Tag[now] = 0;
        return;
    }
    Size[now]--;
    Down(now, L, R);
    if(Tmp[who].y <= mid) Delete(lc, L, mid, who);
    else Delete(rc, mid + 1, R, who);
}

void Query(int now, int L, int R, int l, int r, int who)
{
    if(L == l && R == r)
    {
        if(Size[now]) Merge(Tag[now], who);
		if(!Tag[now]) Tag[now] = who;
        Ans[who] -= Size[now];
        return;
    }
    Down(now, L, R);
    if(l <= mid) Query(lc, L, mid, l, min(mid, r), who);
    if(r > mid) Query(rc, mid + 1, R, max(l, mid + 1), r, who);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        F[i] = i;
        int a1, b1, a2, b2;
        scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
        if(a1 > a2 || b1 > b2) a1 ^= a2 ^= a1 ^= a2, b1 ^= b2 ^= b1 ^= b2;
        if(b1 == b2)
            Hang[++CntHang] = (Line){a1, b1, a2 - a1 + 1, i},
            Tmp[++Cnt] = (node){a1, b1, CntHang, Start_node},
            Tmp[++Cnt] = (node){a2, b2, CntHang, End_node};
        else
            Lie[++CntLie] = (Line){a1, b1, b2 - b1 + 1, i},
            Tmp[++Cnt] = (node){a1, b1, CntLie, line},
            Tmp[++Cnt] = (node){a2, b2, CntLie, line};
    }
    for(int i = 1; i <= Cnt; i++)
    	if(Tmp[i].op == 1) Tmp[i].id += CntHang;
    sort(Tmp + 1, Tmp + Cnt + 1, cmp3);
    int t = 1;
    for(int i = 1; i <= Cnt; i++)
        Tmp[i].y = (Tmp[i].y == Tmp[i + 1].y) ? t : t++;
    sort(Tmp + 1, Tmp + Cnt + 1, cmp2);
    for(int i = 1; i <= Cnt; i++)
    {
        if(Tmp[i].op == Start_node)
            Insert(1, 1, t, i);
        if(Tmp[i].op == End_node)
            Delete(1, 1, t, i);
        if(Tmp[i].op == line)
        {
            Query(1, 1, t, Tmp[i].y, Tmp[i + 1].y, Tmp[i].id);
            i++;
        }
    }
    for(int i = 1; i <= n; i++)
        if(i != getfa(i)) Ans[getfa(i)] += Ans[i];
    for(int i = 1; i <= CntHang; i++)
        Ans[getfa(i)] += Hang[i].len;
    for(int i = CntHang + 1; i <= n; i++)
        Ans[getfa(i)] += Lie[i - CntHang].len;
    for(int i = 1; i <= n; i++)
        ans = max(ans, Ans[i]);
    printf("%lld\n", ans - 1);
    return 0;
}