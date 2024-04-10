#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
 
using namespace std;
 
#define ll long long
 
int main(int argc, char *argv[])
{
    int n,k;
    cin>>n>>k;
    
    ll*f=new ll[n];
    ll*t=new ll[n];
    ll maxe=-20000000000;
    for(int i=0;i<n;i++)
    {
    cin>>f[i]>>t[i];
    if(t[i]>k)
    maxe=max(maxe,f[i]-t[i]+k);
    else
    maxe=max(maxe,f[i]);
    }
    
    cout<<maxe<<endl;
 
    return EXIT_SUCCESS;
}