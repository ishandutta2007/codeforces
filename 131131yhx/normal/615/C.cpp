#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 5010

using namespace std;

char A[M], B[M];

int sta, stb, L[M], R[M], Cnt = 0;

int Match(int x)
{
    int Max = 0, l = 0, r = 0, tmp = stb - x + 1;
    for(int i = sta; i >= 1; i--)
    {
        for(int j = 0; j <= tmp && j + i <= sta + 1; j++)
            if(B[x + j] != A[i + j])
            {
                if(Max < j)
                {
                    Max = j, l = i, r = i + j - 1;
                }
                break;
            }
    }
    for(int i = sta; i >= 1; i--)
    {
        for(int j = 0; j <= tmp && j <= i; j++)
            if(B[x + j] != A[i - j])
            {
                if(Max < j)
                {
                    Max = j, l = i, r = i - j + 1;
                }
                break;
            }
    }
    L[Cnt] = l, R[Cnt] = r;
    return Max;
}

int main()
{
    scanf("%s%s", A + 1, B + 1);
    sta = strlen(A + 1), stb = strlen(B + 1);
    A[0] = 0, A[sta + 1] = 1, B[0] = 2, B[stb + 1] = 3;
    int Now = 1, getans = 1;
    for(; ;)
    {
        Cnt++;
        int tmp = Match(Now);
        if(!tmp)
        {
            getans = 0;
            break;
        }
        Now += tmp;
        if(Now > stb) break;
    }
    if(!getans) puts("-1");
    else
    {
        printf("%d\n", Cnt);
        for(int i = 1; i <= Cnt; i++) printf("%d %d\n", L[i], R[i]);
    }
    return 0;
}