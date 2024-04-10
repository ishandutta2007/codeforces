#include <iostream>

using namespace std;
int main() {
    
    long long n,m,min,max;
    
    cin>>n>>m;
    
    // min
    if(n<=m)
       cout<<0<<" ";
    else if(n>m)
    {
    
    long long k=n/m,q=n%m;
    
    cout<<(m-q)*((k*(k-1))/2ll)+q*((k*(k+1))/2ll)<<" ";
    }
    
    
    //max
    if(n<=m)
       cout<<0<<endl;
    else if(n>m)
    {
    long long x=n-(m-1);
    cout<<(x*(x-1))/2ll<<endl;
    }
    
   
    
    
    return 0;
}