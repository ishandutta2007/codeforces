#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n,k,i;
    cin>>n>>k;
    for(i=1;i<=(k+1)/2;i++)
        cout<<i<<" "<<k-i+2<<" ";
        
    if(i==k-i+2)
        cout<<i<<" ";
    for(i=2+k;i<=n;i++)
        cout<<i<<" ";   
    
    return 0;
}