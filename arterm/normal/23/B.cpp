#include <iostream>

using namespace std;

int main()
{
    long n,t;
    cin>>t;

    while (t--){
        cin>>n;
        if (n<=2)
        cout<<0<<"\n";
        else
        cout<<n-2<<"\n";
    }
    return 0;
}