#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 700010

using namespace std;

long long OP[M], Tree[M], Time[M], L[M], R[M], Tmp[M], Cnt = 0, Ans = 0, Sym[M];

long long State[M];

bool cmp(long long x, long long y)
{
    long long x1 = (x & 1) ? L[(x + 1) / 2] : R[x / 2], y1 = (y & 1) ? L[(y + 1) / 2] : R[y / 2];
    return x1 < y1;
}

bool cmp2(long long x, long long y)
{
    return Time[x] < Time[y] || Time[x] == Time[y] && OP[x] < OP[y] || 
    Time[x] == Time[y] && OP[x] == OP[y] && L[x] < L[y];
}

int main()
{
    long long n;
    scanf("%lld", &n);
    for(long long i = 1; i <= n * 2; i++) R[i] = -2000000000;
    for(long long i = 1; i <= n; i++)
    {
        long long x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        if(x1 > x2) x1 ^= x2 ^= x1 ^= x2;
        if(y1 > y2) y1 ^= y2 ^= y1 ^= y2;
        if(x1 == x2) OP[++Cnt] = 0, L[Cnt] = x1, Time[Cnt] = y1, OP[++Cnt] = 2, 
                     L[Cnt] = x1, Time[Cnt] = y2;
        else OP[++Cnt] = 1, L[Cnt] = x1, R[Cnt] = x2, Time[Cnt] = y1;
    }
    for(long long i = 1; i <= Cnt * 2; i++) Tmp[i] = i;
    sort(Tmp + 1, Tmp + Cnt * 2 + 1, cmp);
    long long t = 0;
    for(long long i = 1; i <= Cnt * 2; i++)
    {
        long long Now = (Tmp[i] & 1) ? L[(Tmp[i] + 1) / 2] : R[Tmp[i] / 2];
        long long Next = (Tmp[i + 1] & 1) ? L[(Tmp[i + 1] + 1) / 2] : R[Tmp[i + 1] / 2];
        Sym[t] = Now;
        if(Tmp[i] & 1)
            L[(Tmp[i] + 1) / 2] = (Now == Next) ? t : t++;
        else
            R[Tmp[i] / 2] = (Now == Next) ? t : t++;
    }
    for(long long i = 1; i <= Cnt; i++) Tmp[i] = i;
    sort(Tmp + 1, Tmp + Cnt + 1, cmp2);
    long long NowTime = Time[Tmp[1]], Max = 0;
    for(long long i = 1; i <= Cnt; i++)
    {
        if(NowTime != Time[Tmp[i]])
            NowTime = Time[Tmp[i]], Max = 0;
        if(OP[Tmp[i]] == 0)
        {
            State[L[Tmp[i]]] ++;
            if(State[L[Tmp[i]]] == 1)
            {
                Ans -= NowTime;
                for(long long j = L[Tmp[i]]; j <= t; j += j & (-j)) Tree[j] ++;
            }
        }
        else if(OP[Tmp[i]] == 2)
        {
            State[L[Tmp[i]]] --;
            if(State[L[Tmp[i]]] == 0)
            {
                Ans += NowTime + 1;
                for(long long j = L[Tmp[i]]; j <= t; j += j & (-j)) Tree[j] --;
            }
        }
        else
        {
            if(R[Tmp[i]] <= Max) continue;
            Ans += (Sym[R[Tmp[i]]] - max(Sym[Max] + 1, Sym[L[Tmp[i]]]) + 1);
            for(long long j = R[Tmp[i]]; j; j -= j & (-j)) Ans -= Tree[j];
            for(long long j = max(Max + 1, L[Tmp[i]]) - 1; j; j -= j & (-j)) Ans += Tree[j];
            Max = max(Max, R[Tmp[i]]);
        }
    }
    printf("%lld\n", Ans);
    return 0;
}