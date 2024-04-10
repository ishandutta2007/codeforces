#include"bits/stdc++.h"
using namespace std;
int ans[10005],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        nn=0;
        cin>>n>>k;
        for(int i=k+1;i<=n;i++)ans[nn++]=i;
        for(int i=(k+1)/2;i<k;i++)ans[nn++]=i;
        cout<<nn<<endl;
        for(int i=0;i<nn;i++)printf("%d%c",ans[i]," \n"[i==nn-1]);
    }
    return 0;
}