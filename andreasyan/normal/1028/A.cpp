#include <bits/stdc++.h>
using namespace std;
const int N=200;

int n,m;
char a[N][N];

int x,y;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("hall.in","r",stdin);
    //freopen("hall.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
    {
        vector<int> v;
        for(int j=0;j<m;++j)
        {
            if(a[i][j]=='B')
                v.push_back(j);
        }
        if(!v.empty())
        {
            y=v[v.size()/2];
            break;
        }
    }
    for(int j=0;j<m;++j)
    {
        vector<int> v;
        for(int i=0;i<n;++i)
        {
            if(a[i][j]=='B')
                v.push_back(i);
        }
        if(!v.empty())
        {
            x=v[v.size()/2];
            break;
        }
    }
    cout<<x+1<<' '<<y+1<<endl;
    return 0;
}