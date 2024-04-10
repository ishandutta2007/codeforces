#include <bits/stdc++.h>
using namespace std;
const int N=55;
const int xx[4]={0,1,0,-1};
const int yy[4]={1,0,-1,0};

char a[N][N];

int b[4],cb[4];

bool c[N][N];

bool dfs(int x,int y,int n,int m)
{
    c[x][y]=true;
    for(int i=0;i<4;++i)
    {
        int hx=x+xx[i];
        int hy=y+yy[i];
        if(hx>=0 && hx<n && hy>=0 && hy<m && a[x][y]==a[hx][hy] && !c[hx][hy])
            dfs(hx,hy,n,m);
    }
}

int bb[4];
bool stg(int n,int m)
{
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            c[i][j]=false;
    for(int k=0;k<4;++k)
        bb[k]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(!c[i][j])
            {
                bb[a[i][j]-'A']++;
                dfs(i,j,n,m);
            }
        }
    }
    for(int i=0;i<4;++i)
        if(bb[i]!=cb[i])
            return false;
    return true;
}

int main()
{
    cin>>b[0]>>b[1]>>b[2]>>b[3];
    cb[0]=b[0];
    cb[1]=b[1];
    cb[2]=b[2];
    cb[3]=b[3];
    int n=50;
    for(int i=0;i<n/2;++i)
    {
        if(i%2==0)
            for(int j=0;j<n;++j)
                a[i][j]='A';
        else
            for(int j=0;j<n;j+=2)
                a[i][j]='A';
    }
    --b[0];
    for(int j=0;j<n;++j)
        a[n/2][j]='B';
    for(int i=n/2+1;i<n;++i)
    {
        if(i%2==0)
            for(int j=0;j<n;++j)
                a[i][j]='B';
        else
            for(int j=0;j<n;j+=2)
                a[i][j]='B';
    }
    --b[1];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(a[i][j]>='A' && a[i][j]<='D')
                continue;
            char x;
            for(int t=0;t<4;++t)
            {
                int ii=i+xx[t];
                int jj=j+yy[t];
                if(ii>=0 && ii<n && jj>=0 && jj<n)
                    x=a[ii][jj];
            }
            for(int k=0;k<4;++k)
            {
                if(b[k])
                {
                    if(x!=k+'A')
                    {
                        b[k]--;
                        a[i][j]=k+'A';
                        break;
                    }
                }
            }
            if(!(a[i][j]>='A' && a[i][j]<='D'))
                a[i][j]=x;
        }
    }
    cout<<n<<' '<<n<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}