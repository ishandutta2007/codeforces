#include"bits/stdc++.h"
using namespace std;
int a[100005];
int l[305],r[305];
int pos[800];
int maxs[800];
int mins[800];
int nn;
vector<int>save;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    set<int>s;
    s.insert(1);
    s.insert(n+1);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",l+i,r+i);
        s.insert(l[i]);
        s.insert(r[i]+1);
    }
    for(auto p:s)
    {
        pos[nn++]=p;//cout<<"<<<"<<p<<endl;
    }
    for(int i=0;i<nn-1;i++)
    {
        maxs[i]=-1e9;
        mins[i]=1e9;
        for(int j=pos[i];j<pos[i+1];j++)
        {
            maxs[i]=max(maxs[i],a[j]);
            mins[i]=min(mins[i],a[j]);
        }//cout<<"<<<"<<maxs[i]<<" "<<mins[i]<<endl;
    }
    int best=-1;int besti,bestj;
    int smax,smin;
    for(int i=0;i<nn-1;i++)for(int j=0;j<nn-1;j++)
    {
        int ans=maxs[i]-mins[j];
        for(int k=0;k<m;k++)
        {
            if(l[k]<=pos[j]&&pos[j+1]-1<=r[k]&&(l[k]>pos[i]||pos[i+1]-1>r[k]))
            {
                ans++;
            }
        }
        if(ans>best)
        {
            best=ans;
            besti=i;
            bestj=j;
        }
    }
    {
        int i=besti,j=bestj;
        for(int k=0;k<m;k++)
        {
            if(l[k]<=pos[j]&&pos[j+1]-1<=r[k]&&(l[k]>pos[i]||pos[i+1]-1>r[k]))
            {
                save.push_back(k);
            }
        }
    }
    cout<<best<<endl;
    cout<<save.size()<<endl;
    for(auto pp:save)printf("%d ",pp+1);
    return 0;
}