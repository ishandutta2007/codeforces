#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    long n,i,a=0;
    cin>>n;
    for (i=0; i<n-1; ++i){
        a+=(i+1);
        a%=n;
        cout<<a+1<<" ";
        }
    return 0;
}