#include <stdio.h>

int N,ans,M;
unsigned hyper[8125011];

inline bool mem(int n)
{
    return (hyper[n>>5]>>(n&31))&1;
}

inline void write(int n)
{
    if (!mem(n)) hyper[n>>5] += 1<<(n&31);
}

int main()
{
    int i,j;
    scanf("%d%d",&N,&M);
    if(N<=2&&M>=2) ans++;
    M++;
    for (i=3;i<M;i+=2){
        if (mem(i>>1)) continue;
        if(i%4==1&&i>=N)ans++;
        if (i > M/i) continue;
        for (j=i*i;j<M;j+=(i<<1)) write(j>>1);
    }
    printf("%d",ans);
}