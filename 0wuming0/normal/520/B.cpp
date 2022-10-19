#include"bits/stdc++.h"
using namespace std;
int ans[10004];
int a,b;
int solve(int k)
{//cout<<k<<endl;
    if(k>=b)return k-b;
    if(!ans[k])
    {
        ans[k]=1e9;
        if(k==1)ans[k]=solve(2*k)+1;
        else ans[k]=min(solve(2*k),solve(k-1))+1;
    }
    return ans[k];
}
int main()
{
    cin>>a>>b;
    cout<<solve(a)<<endl;
    return 0;
}