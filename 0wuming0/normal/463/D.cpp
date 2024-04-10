#include"bits/stdc++.h"
using namespace std;
int a[5][1005];
int pos[5][1005];
int n,k;
vector<int>in[1005];
void checkpos(int i,int j)
{
    for(int c=0;c<k;c++)if(pos[c][i]<pos[c][j])return;
    in[i].push_back(j);
}
int ans[1005];
int getans(int i)
{
    if(ans[i])return ans[i];
    int s=0;
    for(vector<int>::iterator it=in[i].begin();it!=in[i].end();++it)
    {
        s=max(s,getans(*it));
    }
    ans[i]=1+s;
    return ans[i];
}
int main()
{
    cin>>n>>k;
    for(int j=0;j<k;j++)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[j][i];
            pos[j][a[j][i]]=i;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i-j)
    {
        checkpos(i,j);
    }
    int m=0;
    for(int i=1;i<=n;i++)m=max(m,getans(i));
    cout<<m<<endl;
    return 0;
}