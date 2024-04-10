#include <iostream>
using namespace std;

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    long long n,a,b,c;
    cin>>n>>a>>b>>c;

    long long l=0,r=n/(b-c);
    while (l<r)
    {
        long long m=(l+r)/2;
        if(m*(b-c)+b<=n)
            l=m+1;
        else
            r=m;
    }

    cout<<max(n/a,l+(n-l*(b-c))/a);
    return 0;
}