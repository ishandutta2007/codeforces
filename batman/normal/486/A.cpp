#include <iostream>
using namespace std;
#define ll long long
ll n;

int main()
{
    cin>>n;
    if(n%2==0)
        cout<<n/2<<endl;
    else
        cout<<(-1)*((n+1)/2)<<endl;
    
    return 0;
}