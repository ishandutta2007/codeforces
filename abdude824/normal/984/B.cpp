#include <bits/stdc++.h>
using namespace std;
char s[109][109];
int main()
{
    int n,m,i,j,k,c,dx[]={-1,0,1,-1,1,-1,0,1},dy[]={-1,-1,-1,0,0,1,1,1};
    for(scanf("%d%d",&n,&m),i=1; i<=n; ++i) scanf("%s",s[i]+1);
    for(i=1; i<=n; ++i) for(j=1; j<=m; ++j)
    {
        if(s[i][j]=='.') s[i][j]='0';
        for(c=k=0; k<8; ++k) if(s[i+dx[k]][j+dy[k]]=='*') ++c;
        if('0'<=s[i][j]&&s[i][j]<='9'&&s[i][j]!=c+'0') printf("NO\n"),exit(0);
    }
    printf("YES\n"),exit(0);
}