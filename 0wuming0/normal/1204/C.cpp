#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,a[105][105],inf=100000;
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%1d",&a[i][j]);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(a[i][j]==0)a[i][j]=inf;
    int m;
    cin>>m;
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)
    {
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    }
    //for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<a[i][j];cout<<endl;}
    int x,y;
    cin>>x>>y;
    m-=2;
    vector<int>ans;
    while(m--)
    {
        int t;
        scanf("%d",&t);
        if(a[x-1][t-1]==a[x-1][y-1]+a[y-1][t-1]&&x!=t)y=t;
        else
        {
            ans.push_back(x);
            x=y;
            y=t;
        }
    }
    cout<<ans.size()+2<<endl;
    for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
    cout<<x<<' '<<y<<endl;
    return 0;
}
/*
4
0110
0010
0001
1000
4
1 2 3 4
*/