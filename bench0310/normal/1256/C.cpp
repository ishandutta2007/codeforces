#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,d;
    scanf("%d%d%d",&n,&m,&d);
    int c[m];
    for(int i=0;i<m;i++) scanf("%d",&c[i]);
    vector<int> res(n+1,0);
    int idx=n;
    for(int o=m-1;o>=0;o--)
    {
        for(int i=idx;i>idx-c[o];i--) res[i]=o+1;
        idx-=c[o];
    }
    idx++;
    int now=0;
    int id=0; //platform
    bool b=1;
    while(now<n)
    {
        if(now+d>=idx) break;
        if(id==m)
        {
            b=0;
            break;
        }
        for(int i=idx;i<idx+c[id];i++) res[i]=0;
        for(int i=now+d;i<now+d+c[id];i++) res[i]=id+1;
        now+=(d+c[id]-1);
        idx+=c[id];
        id++;
    }
    if(b)
    {
        printf("YES\n");
        for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
    }
    else printf("NO\n");
    return 0;
}