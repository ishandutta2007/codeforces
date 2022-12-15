#include<bits/stdc++.h>
using namespace std;
bool hasans[5][5][100];
bool res[5][5][100][5][5];
vector<int> flag[100010];
int calc(int n,int m)
{
    int ret=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            int cur=flag[i][j]+flag[i+1][j]+flag[i][j+1]+flag[i+1][j+1];
            if(cur==4)ret+=4;
            else if(cur==3)ret++;
        }
    }
    return ret;
}
void init()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=i;k++)flag[k].resize(j+1);
            for(int k=1;k<(1<<(i*j));k++)
            {
                for(int l=1;l<=i;l++)
                {
                    for(int s=1;s<=j;s++)
                    {
                        if((k>>((l-1)*j+(s-1)))&1)flag[l][s]=1;
                        else flag[l][s]=0;
                    }
                }
                int vl=calc(i,j);
                if(!hasans[i][j][vl])
                {
                    hasans[i][j][vl]=1;
                    for(int l=1;l<=i;l++)
                    {
                        for(int s=1;s<=j;s++)res[i][j][vl][l][s]=flag[l][s];
                    }
                }
            }
        }
    }
}
int n,m,K;
void solve()
{
    scanf("%d%d%d",&n,&m,&K);
    if(K>(n-1)*(m-1)*4)
    {
        puts("-1\n");
        return;
    }
    bool iv=0;
    if(n<5&&m<5)
    {
        if(!hasans[n][m][K])puts("-1\n");
        else
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)putchar(res[n][m][K][i][j]?'*':'.');
                putchar('\n');
            }
            putchar('\n');
        }
        return;
    }
    if(!K)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)putchar(i+j==2?'*':'.');
            putchar('\n');
        }
        putchar('\n');
        return;
    }
    if(n>m)swap(n,m),iv=1;
    if(n==3&&m>=5&&K==8*(m-2))
    {
        if(!iv)
        for(int i=1;i<=n;i++)
        {
            putchar('.');
            for(int j=2;j<=m;j++)putchar('*');
            putchar('\n');
        }
        else
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)putchar(i==1?'.':'*');
            putchar('\n');
        }
        putchar('\n');
        return;
    }
    for(int i=1;i<=n;i++)flag[i].resize(m+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)flag[i][j]=0;
    for(int i=1;i<=m;i++)flag[1][i]=1;
    int sk=K;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int fx,fy;
            if(j==1)fx=i-1,fy=m;
            else fx=i,fy=j-1;
            if(fx!=n&&K<4)
            {
                if(K==1)
                {
                    if(fy>=2)flag[fx+1][1]=1;
                    else flag[fx][m]=1;
                }
                else if(K==2)
                {
                    if(fy>=3)flag[fx+1][2]=1;
                    else flag[fx][m-1]=1;
                }
                else if(K==3)
                {
                    if(fy==m)flag[fx+1][2]=1,flag[fx+1][m]=1;
                    else if(fy==m-1)flag[fx][m]=1;
                    else if(fy>=3)flag[fx+1][2]=1,flag[fx][m]=1;
                    else if(fy==2)flag[fx+1][1]=1,flag[fx][m-1]=1;
                    else flag[fx][3]=1,flag[fx][m]=1;
                }
                goto output;
            }
            else if(K<4||(i==n&&fy==m-4))
            {
                for(int k=0;k<16;k++)
                {
                    for(int l=0;l<4;l++)flag[i][m-l]=(k>>l)&1;
                    if(calc(n,m)==sk)goto output;
                }
                puts("-1\n");
                return;
            }
            if(j==1)K--;
            else if(j==m)K-=3;
            else K-=4;
            flag[i][j]=1;
        }
    }
    output:
    if(!iv)
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            putchar(flag[i][j]?'*':'.');
        }
        putchar('\n');
    }
    else
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            putchar(flag[j][i]?'*':'.');
        }
        putchar('\n');
    }
    putchar('\n');
}
int T;
int main()
{
    init();
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}