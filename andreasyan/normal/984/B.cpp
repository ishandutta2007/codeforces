#include <bits/stdc++.h>
using namespace std;
const int N=102;
const int xx[8]={0,1,0,-1,-1,1,-1,1};
const int yy[8]={1,0,-1,0,-1,1,1,-1};

int n,m;
char a[N][N];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i][j]=='*')
                continue;
            int yans=0;
            for(int k=0;k<8;++k)
            {
                int x=i+xx[k];
                int y=j+yy[k];
                if(x>=0 && x<n && y>=0 && y<m)
                    if(a[x][y]=='*')
                        ++yans;
            }
            int ans;
            if(a[i][j]=='.')
                ans=0;
            else
                ans=a[i][j]-'0';
            if(ans!=yans)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}