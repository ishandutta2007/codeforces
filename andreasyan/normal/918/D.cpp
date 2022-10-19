#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct ban
{
    int x;
    char c;
};
const int N=102;

int n,m;
bool c[N];
vector<ban> a[N];
int ans[N][N][N];
void stg(int i,int j,char u)
{
    for(int k=0;k<a[i].size();++k)
    {
        ban h=a[i][k];
        if(h.c>=u)
        {
            if(ans[j][h.x][h.c-'a']==0)
                stg(j,h.x,h.c);
            if(ans[j][h.x][h.c-'a']==2)
            {
                ans[i][j][u-'a']=1;
                return;
            }
        }
    }
    ans[i][j][u-'a']=2;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y;
        char u;
        cin>>x>>y>>u;
        ban t;
        t.c=u;
        t.x=y;
        a[x].push_back(t);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(ans[i][j][0]==0)
                stg(i,j,'a');
            if(ans[i][j][0]==1)
                cout<<'A';
            else
                cout<<'B';
        }
        cout<<endl;
    }
    return 0;
}