#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    cout.setf(ios::fixed);
    cout.precision(7);
    
    long long n,m;
    
    cin>>n>>m;
    
    long long*t=new long long[n], *cost=new long long[n], *T=new long long[n], *x=new long long[n];
    
    for(long long i=0;i<n;i++)
    cin>>t[i]>>T[i]>>x[i]>>cost[i];
    
    long long ans=0;
    
    for(long long i=0;i<n;i++)
    {
            long long c1=cost[i],c2;
            
            if(t[i]+m>T[i])
            c1+=m*x[i];
            
            if(t[i]>=T[i])
            c2=2000000000000000000.0;
            else
            c2=cost[i]*( m/(T[i]-t[i]) + bool(m%(T[i]-t[i])) );
            
            ans+=min(c1,c2);
    }
    
    cout<<ans<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}