#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define INF ((ll)1e14)
#define N (2002)
#define MOD ((ll)1e9+7)

ll n,m;
char s[N][N];

ll t(ll x,ll y)
{
    ll num=0;
    for(int q1=-1;q1<=1;q1++)
        for(int q2=-1;q2<=1;q2++)
            if((!q1 ^ !q2) && s[x+q1][y+q2]=='.')
                num++;
    return num;
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf(" %c",&s[i][j]);
    queue <pair<ll,ll> > q;     
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(t(i,j)==1)
                q.push({i,j});          
    while(q.size())
    {
        ll x=q.front().first,y=q.front().second;
        q.pop();
        if(s[x][y]!='.' || t(x,y)!=1)continue;
        if(s[x-1][y]=='.')
        {
            s[x][y]='v',s[x-1][y]='^';
            for(int q1=-1;q1<=1;q1++)
                for(int q2=-1;q2<=1;q2++)
                    if((!q1 ^ !q2) && s[x-1+q1][y+q2]=='.' && t(x-1+q1,y+q2)==1)
                        q.push({x-1+q1,y+q2});              
        }   
        if(s[x+1][y]=='.')
        {
            s[x][y]='^',s[x+1][y]='v';
            for(int q1=-1;q1<=1;q1++)
                for(int q2=-1;q2<=1;q2++)
                    if((!q1 ^ !q2) && s[x+1+q1][y+q2]=='.' && t(x+1+q1,y+q2)==1)
                        q.push({x+1+q1,y+q2});              
        }
        if(s[x][y-1]=='.')
        {
            s[x][y]='>',s[x][y-1]='<';
            for(int q1=-1;q1<=1;q1++)
                for(int q2=-1;q2<=1;q2++)
                    if((!q1 ^ !q2) && s[x+q1][y-1+q2]=='.' && t(x+q1,y-1+q2)==1)
                        q.push({x+q1,y-1+q2});              
        }
        if(s[x][y+1]=='.')
        {
            s[x][y]='<',s[x][y+1]='>';
            for(int q1=-1;q1<=1;q1++)
                for(int q2=-1;q2<=1;q2++)
                    if((!q1 ^ !q2) && s[x+q1][y+1+q2]=='.' && t(x+q1,y+1+q2)==1)
                        q.push({x+q1,y+1+q2});              
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='.')
                return printf("Not unique"),0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%c",s[i][j]);
        printf("\n");   
    }
                    
    return 0;
}