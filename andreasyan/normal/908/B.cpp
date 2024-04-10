#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=105;
struct ban
{
    int x,y;
};

int n,m;
char a[N][N];
char b[N];
ban s,e;
int xx[4]={1,0,-1,0};
int yy[4]={0,-1,0,1};
int t[4]={0,1,2,3};
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
            if(a[i][j]=='S')
            {
                a[i][j]='.';
                s.x=i;
                s.y=j;
            }
            if(a[i][j]=='E')
            {
                a[i][j]='.';
                e.x=i;
                e.y=j;
            }
        }
    }
    cin>>b;
    int k=strlen(b);
    int ans=0;
    do
    {
        bool z=false;
        ban u=s;
        for(int i=0;i<k;++i)
        {
            u.x+=xx[t[b[i]-'0']];
            u.y+=yy[t[b[i]-'0']];
            if(u.x<0 || u.x>=n || u.y<0 || u.y>=m)
            {
                break;
            }
            if(a[u.x][u.y]=='#')
            {
                break;
            }
            if(u.x==e.x && u.y==e.y)
            {
                z=true;
                break;
            }
        }
        if(z)
            ans++;
    }while(next_permutation(t,t+4));
    cout<<ans<<endl;
    return 0;
}