#include<cstdio>
int cnt[101010];
int a[101010];
void solve(int N)
{
    for(int i=2; i*i<=N; i++)
    {
        if(N%i==0) cnt[i]++;
        while(N%i==0)
        {
            N/=i;
        }
    }
    if(N!=1) cnt[N]++;
}
int main()
{
    int N;
    scanf("%d",&N);
    int ans = 1;
    for(int i=0; i<N; i++)
    {
        scanf("%d",a+i);
        solve(a[i]);
    }
    for(int i=2; i<=100000;i++)
        if(ans<cnt[i]) ans = cnt[i];
    printf("%d\n",ans);
}