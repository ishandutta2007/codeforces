#include"bits/stdc++.h"
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll s=0;
        int m=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            s+=a;
            m=max(m,a);
        }
        if(s==0)cout<<0<<endl;
        else if(2*m-s<1)cout<<1<<endl;
        else cout<<2*m-s<<endl;
    }
    return 0;
}