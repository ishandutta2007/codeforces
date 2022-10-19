#include <iostream>

using namespace std;

int main()
{
    long n;
    cin>>n;
    if (n<=2)
    cout<<-1;
    else{
        cout<<"2 3 1 ";
        for (long i=4; i<=n; ++i)
        cout<<i<<" ";
    }
    return 0;
}