#include <bits/stdc++.h>
using namespace std;
const int N=102;

int n;
char a[4][N][N];
int ans1[4];
int ans2[4];

int main()
{
    cin>>n;
    for(int k=0;k<4;++k)
    {
        for(int i=0;i<n;++i)
        {
            cin>>a[k][i];
        }
        int t=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if((a[k][i][j]-'0')^t)
                    ans1[k]++;
                t^=1;
            }
        }
        t=1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if((a[k][i][j]-'0')^t)
                    ans2[k]++;
                t^=1;
            }
        }
    }
    int ans=999999999;
    for(int x=1;x<(1<<4);++x)
    {
        int yans=0;
        int q=0;
        for(int i=0;i<4;++i)
        {
            if((x|(1<<i))==x)
            {
                ++q;
                yans+=ans1[i];
            }
            else
                yans+=ans2[i];
        }
        if(q==2)
            ans=min(ans,yans);
    }
    cout<<ans<<endl;
    return 0;
}