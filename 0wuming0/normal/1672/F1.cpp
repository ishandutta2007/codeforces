#include"bits/stdc++.h"
using namespace std;
int a[200005];
vector<int>save[200005];
vector<int>v[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            save[a[i]].push_back(i);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<save[i].size();j++)
            {
                v[j+1].push_back(save[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<v[i].size();j++)
            {
                swap(a[v[i][j]],a[v[i][j-1]]);
            }
        }
        for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
        for(int i=0;i<=n;i++)
        {
            save[i].clear();
            v[i].clear();
        }
    }
    return 0;
}