#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        long long int n,newval,ans=0;cin>>n;
        int flag=0;
        
        while(n)
        {
            if(n%2==1)
            newval=n-1;
            else if(n==4)
            newval=2;
            else
            {
                newval=n/2;
                if(newval%2==0)
                newval=n-1;
                else
                newval=n/2;
            }
            
            if(flag==0)
            {
                ans+=n-newval;
                flag=1;
            }
            else
            flag=0;
            
            n=newval;
            
        }
        
        cout<<ans<<endl;
    }

    return 0;
}