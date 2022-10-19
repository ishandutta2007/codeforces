#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        n*=m;
        int q;
        int num=0;
        int ans=0;
        int mins=1000;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&q);
            if(q<0)num++;
            mins=min(mins,abs(q));
            ans+=abs(q);
        }
        cout<<ans-2*(num%2==0?0:mins)<<endl;
    }
    return 0;
}