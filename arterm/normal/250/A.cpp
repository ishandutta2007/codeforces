#include <iostream>

using namespace std;

long n,b[100],t=0,c=0;

int main()
{
    cin>>n;
    for (long a,i=0; i<n; ++i){
        cin>>a;
        if (a<0)
        if (c<2)
        c++;
        else
        c=1,t++;

        b[t]++;
    }
    cout<<t+1<<"\n";
    for (long i=0; i<=t; ++i)
    cout<<b[i]<<" ";
    return 0;
}