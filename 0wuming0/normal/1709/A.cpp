#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        int a[4];
        cin>>a[1]>>a[2]>>a[3];
        bool vis[4]={0};
        set<int>s;
        s.insert(x);
        for(int i=0;i<5;i++)
        {
            for(int j=1;j<=3;j++)if(s.find(j)!=s.end())
            {
                vis[j]=1;
                s.insert(a[j]);
            }
        }
        if(vis[1]==vis[2]&&vis[2]==1&&vis[3]==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}