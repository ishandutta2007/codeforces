#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e5+1;
int n,r1,c1,r2,c2,vt[52][52],kt=1,kq=1e9;
char a[52][52];
vector<int>a1,b1,a2,b2;
void dfs(int x,int y)
{
    vt[x][y]=0;
    if (a[x-1][y]=='1' || a[x+1][y]=='1' || a[x][y-1]=='1' || a[x][y+1]=='1')
    {
        if (kt==1)
        {
        a1.push_back(x);
        b1.push_back(y);
        }
        else
        {
            a2.push_back(x);
            b2.push_back(y);
        }
    }
    if (vt[x-1][y]==1 && a[x-1][y]=='0') dfs(x-1,y);
    if (vt[x+1][y]==1 && a[x+1][y]=='0') dfs(x+1,y);
    if (vt[x][y-1]==1 && a[x][y-1]=='0') dfs(x,y-1);
    if (vt[x][y+1]==1 && a[x][y+1]=='0') dfs(x,y+1);
}

int main()
{
    //freopen("c.inp","r",stdin);
    cin>>n>>r1>>c1>>r2>>c2;
    char ch;
    for (int i=1;i<=n;i++)
    {
        ch=getchar();
        for (int j=1;j<=n;j++)
    {
        vt[i][j]=1;
        a[i][j]=getchar();
    }
    }
    dfs(r1,c1);
    if (vt[r2][c2]==0)
    {
        cout<<0;
        return 0;
    }
    kt=2;
    dfs(r2,c2);
    for (int i=0;i<a1.size();i++)
        for (int j=0;j<a2.size();j++) kq=min(kq,abs(a1[i]-a2[j])*abs(a1[i]-a2[j])+abs(b1[i]-b2[j])*abs(b1[i]-b2[j]));
    cout<<kq;

    return 0;
}