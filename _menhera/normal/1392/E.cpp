#include<bits/stdc++.h>
using namespace std;
const int MAXN = 25;
long long arr[MAXN][MAXN];
int N;
long long down_max(int x, int y)
{
    long long ans = 0;
    //to N-1, N-1
    ans += arr[x+1][y]; ++x;
    while(y<N-1)
    {
        ans += arr[x][y+1]; ++y;
    }
    while(x<N-1)
    {
        ans += arr[x+1][y]; ++x;
    }
    return ans;
}
long long right_min(int x, int y)
{
    long long ans = 0;
    //to N-1, N-1
    ans += arr[x][y+1]; ++y;
    while(x<N-1)
    {
        ans += arr[x+1][y]; ++x;
    }
    while(y<N-1)
    {
        ans += arr[x][y+1]; ++y;
    }
    return ans;
}

int main()
{
    scanf("%d", &N);
    for(int i=N-2; i>=0; --i)
    {
        for(int j=1; j<N; ++j)
        {
            long long v1 = right_min(i, j-1);
            long long v2 = down_max(i, j-1);
            arr[i][j] = v2-v1+1;
        }
    }
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
            printf("%lld ", arr[i][j]);
        puts("");
    }
    fflush(stdout);
    int Q; scanf("%d", &Q);
    for(int i=0; i<Q; ++i)
    {
        long long v; scanf("%lld", &v);
        int x=0, y=0; printf("%d %d\n", 1, 1);
        while(x!=N-1 || y!=N-1)
        {
            if(x==N-1) ++y;
            else if(y==N-1) ++x;
            else if(v <= down_max(x, y)) ++x;
            else ++y;
            v -= arr[x][y];
            printf("%d %d\n", x+1, y+1);
        }
        fflush(stdout);
    }
}