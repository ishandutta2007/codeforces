#include <stdio.h>
#include <queue>

char arr[500][501];
int cnt[500];
bool chk[501][501];
long long mem[501][501];

struct str
{
    int x;
    int y;
    str(int ax,int ay) : x(ax),y(ay){}
};

std::queue<str> q;

int main()
{
    int n,m,mod,x=0,y=0,r,i,j;
    scanf("%d%d%d",&n,&m,&mod);
    for(i=0;i<m;i++)
        scanf("%s",arr[i]);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(arr[i][j]=='1')
                cnt[j]++;
    for(i=0;i<n;i++)
    {
        if(cnt[i]==0)
            x++;
        else if(cnt[i]==1)
            y++;
    }
    q.push(str(x,y));
    chk[x][y]=1;
    mem[x][y]=1;
    while(!q.empty())
    {
        x=q.front().x;
        y=q.front().y;
        q.pop();
        if(2<=x&&y<=n-2)
        {
            if(!chk[x-2][y+2])
            {
                chk[x-2][y+2]=1;
                q.push(str(x-2,y+2));
            }
            mem[x-2][y+2]=(mem[x-2][y+2]+mem[x][y]*x*(x-1)/2)%mod;
        }
        if(1<=x&&y<=n-1)
        {
            if(!chk[x-1][y+1])
            {
                chk[x-1][y+1]=1;
                q.push(str(x-1,y+1));
            }
            mem[x-1][y+1]=(mem[x-1][y+1]+mem[x][y]*x*(x-1)/2)%mod;
        }
        if(1<=x)
        {
            if(!chk[x-1][y])
            {
                chk[x-1][y]=1;
                q.push(str(x-1,y));
            }
            mem[x-1][y]=(mem[x-1][y]+mem[x][y]*x*y)%mod;
        }
        if(2<=y)
        {
            if(!chk[x][y-2])
            {
                chk[x][y-2]=1;
                q.push(str(x,y-2));
            }
            mem[x][y-2]=(mem[x][y-2]+mem[x][y]*y*(y-1)/2)%mod;
        }
    }
    printf("%I64d",mem[0][0]%mod);
    return 0;
}