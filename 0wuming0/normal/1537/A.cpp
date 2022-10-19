#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int s=0;
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            s+=k-1;
        }
        if(s==0)cout<<0<<endl;
        else if(s<0)cout<<1<<endl;
        else
        {
            cout<<s<<endl;
        }
    }
    return 0;
}