#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e3+10;
int a[maxn][maxn],n,k,c[maxn][maxn],r[maxn][maxn],s[maxn][maxn];

void read()
{
    cin>>n>>k;
    char ch=getchar();
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            ch=getchar();
            a[i][j]=(ch=='B');
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
        ch=getchar();
    }
}

int area(int r1,int c1,int r2,int c2)
{
    return s[r2][c2]-s[r1-1][c2]-s[r2][c1-1]+s[r1-1][c1-1];
}

void process()
{
    for (int i=1;i<=n;i++)
    {
        r[i][0]=(area(i,1,i,n)==0)+r[i-1][0];
        c[i][0]=(area(1,i,n,i)==0)+c[i-1][0];
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n-k+1;j++)
        {
            r[i][j]=(area(i,1,i,n)-area(i,j,i,j+k-1)==0);
            c[i][j]=(area(1,i,n,i)-area(j,i,j+k-1,i)==0);
            r[i][j]+=r[i-1][j];
            c[i][j]+=c[i-1][j];
        }
    int ans=0;
    for (int i=1;i<=n-k+1;i++)
        for (int j=1;j<=n-k+1;j++)
        {
            int kq=r[i-1][0]+r[n][0]-r[i+k-1][0]+c[j-1][0]+c[n][0]-c[j+k-1][0]+r[i+k-1][j]-r[i-1][j]+c[j+k-1][i]-c[j-1][i];
            ans=max(ans,kq);
        }
    cout<<ans;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}