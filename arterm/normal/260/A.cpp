#include <iostream>

using namespace std;

int main()
{
    long n,a,b;
    cin>>a>>b>>n;
    for (long i=0; i<10; ++i)
    if ((10*a+i)%b==0){
        cout<<10*a+i;
        for (long j=1; j<n; ++j)
        cout<<"0";
        return 0;
    }
    cout<<-1;
    return 0;
}