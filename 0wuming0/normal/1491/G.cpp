#include"bits/stdc++.h"
using namespace std;
int ans[200005][2],nn;
int a[200005],op;
int vis[200005];
int last;
int add(int x,int y)
{
    ans[nn][0]=x;
    ans[nn][1]=y;
    nn++;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)if(vis[i]==0)
    {
        op++;
        int now=i;
        while(vis[now]==0)
        {
            last=now;
            vis[now]=1;
            now=a[now];
        }
    }
    int flag=0,tt;
    for(int i=1,j=0;i<=n;i++)if(vis[i]==1)
    {
        j++;
        flag^=1;
        int now=i;
        while(vis[now]==1)
        {
            last=now;
            vis[now]=2;
            now=a[now];
        }
        if(flag==1)tt=i;
        else
        {
            add(tt,i);
            vis[tt]=vis[i]=3;
            now=i;
            now=a[now];
            while(vis[now]==2)
            {
                vis[now]=3;
                add(now,tt);
                now=a[now];
            }
            now=tt;
            now=a[now];
            while(vis[now]==2)
            {
                vis[now]=3;
                add(now,i);
                now=a[now];
            }
            add(tt,i);
        }
        if(j==op&&flag==1)
        {
            tt=i;
            now=i;
            now=a[now];
            int ttt=now;
            vis[now]=vis[tt]=3;
            if(now==tt)break;
            if(a[now]==tt)
            {
                int aa;
                if(tt!=1&&ttt!=1)aa=1;
                if(tt!=2&&ttt!=2)aa=2;
                if(tt!=3&&ttt!=3)aa=3;
                add(tt,aa);
                add(ttt,aa);
                add(tt,aa);
                break;
            }
            add(now,tt);
            now=a[now];
            int lastnow;
            while(vis[now]==2)
            {
                vis[now]=3;
                add(now,tt);
                lastnow=now;
                now=a[now];
            }
            nn--;
            now=lastnow;
            add(ttt,now);
            add(tt,now);
            add(tt,ttt);
            break;
        }
    }
    cout<<nn<<endl;
    for(int i=0;i<nn;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0;
}
/*
4
3 2 1 4

7
1 5 2 3 4 7 6

6
6 1 2 3 4 5
*/