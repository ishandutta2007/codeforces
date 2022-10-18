#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const double pi=3.141592653589793238462643383279;

int main(int argc, char *argv[])
{
    cout.setf(ios::fixed);
    
    cout.precision(15);
    
    int n;
    
    cin>>n;
    
    double*r=new double[n];
    
    for(int i=0;i<n;i++)
    cin>>r[i];
    
    sort(r,r+n);
    
    double ans=0;
    
    if(n%2)
    {
    ans=r[0]*r[0]*pi;
    
    for(int i=2;i<n;i+=2)
    ans+=r[i]*r[i]*pi-r[i-1]*r[i-1]*pi;
    }
    else
    {
    for(int i=1;i<n;i+=2)
    ans+=r[i]*r[i]*pi-r[i-1]*r[i-1]*pi;
    }
    //cout<<r[0]<<' '<<r[1]<<' '<<r[2]<<' '<<r[3]<<endl;
    cout<<ans<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}