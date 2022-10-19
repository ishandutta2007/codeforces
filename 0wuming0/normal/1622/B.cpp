#include"bits/stdc++.h"
using namespace std;
int p[200005],q[200005];
char s[200005];
int ans[200005];
bool cmp(int x,int y)
{
    if(s[x]!=s[y])return s[x]<s[y];
    return p[x]<p[y];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",p+i);
            q[i]=i;
        }
        scanf("%s",s+1);
        sort(q+1,q+n+1,cmp);
        for(int i=1;i<=n;i++)ans[q[i]]=i;
        for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 0;
}