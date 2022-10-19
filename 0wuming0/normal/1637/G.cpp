#include"bits/stdc++.h"
using namespace std;
int ans[1000006][2],nn;
int bit[20];
void add(int x,int y)
{
    ans[nn][0]=x;
    ans[nn++][1]=y;
}
void solve(int n,int ad)
{
    if(n==0)return;
    if(n==1)
    {
        bit[ad]++;
        return;
    }
    if(n==2)
    {
        bit[ad]++;
        bit[ad+1]++;
        return;
    }
    int k=1;
    int now=0;
    while(k<n)
    {
        k<<=1;
        now++;
    }
    if(k==n)
    {
        bit[now+ad]++;
        n--;
    }
    bit[now-1+ad]++;
    int l,r;
    for(l=k/2-1,r=k/2+1;r<=n;l--,r++)
    {
        add(l<<ad,r<<ad);
        bit[now+ad]++;
    }
    solve(l,ad);
    solve(n-k/2,ad+1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==2)
        {
            printf("-1\n");
            continue;
        }
        nn=0;
        for(int i=0;i<20;i++)bit[i]=0;
        solve(n,0);
        for(int i=0;i<20;i++)if(bit[i]>=2)
        {
            add(1<<i,1<<i);
            bit[i+1]++;
            bit[i]-=2;
            break;
        }
        int aim=19;
        while(bit[aim]==0)aim--;
        for(int i=0;i<aim;i++)
        {
            if(bit[i]%2)
            {
                bit[i]--;
                bit[i+1]++;
                add(0,1<<i);
                add(1<<i,1<<i);
            }
            bit[i]/=2;
            bit[i+1]+=bit[i];
            while(bit[i]--)
            {
                add(1<<i,1<<i);
                add(0,1<<aim);
            }
        }
        add(0,1<<aim);
        printf("%d\n",nn);
        for(int i=0;i<nn;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    return 0;
}