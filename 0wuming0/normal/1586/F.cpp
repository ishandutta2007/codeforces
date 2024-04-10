#include"bits/stdc++.h"
using namespace std;
int n,k;
int lb(int a,int b)
{
    if(a==b)return 0;
    return lb(a/k,b/k)+1;
}
int main()
{
    vector<int>v;
    int ans=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
    {
        v.push_back(lb(i,j));
    }
    for(auto c:v)ans=max(c,ans);
    cout<<ans<<endl;
    for(int i=0;i<v.size();i++)printf("%d%c",v[i]," \n"[i==v.size()-1]);
    return 0;
}