#include"bits/stdc++.h"
using namespace std;
int vis[200005];
int main()
{
    int n;
    cin>>n;
    n++;
    while(--n)
    {
        int t;
        cin>>t;
        vis[t]=n;
    }
    int ans=0,best;
    for(int i=0;i<200005;i++)if(vis[i]>ans)ans=vis[i],best=i;
    cout<<best<<endl;
    return 0;
}