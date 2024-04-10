////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
     cin>>n;
     for(int i=1,q=(n-1)/2,q2=1;i<=n/2+1;i++,q--,q2+=2)
     {
        for(int j=1;j<=n;j++)
        {
            if(j<=q || j>q+q2)
                cout<<"*";
            else
                cout<<"D";
        }
        cout<<endl;
        
     }
     for(int i=(n+1)/2,q=1,q2=n-2;i<n;i++,q++,q2-=2)
     {
        for(int j=1;j<=n;j++)
        {
            if(j<=q || j>q+q2)
                cout<<"*";
            else
                cout<<"D";  
        }
        cout<<endl;
     }
     return 0;
}