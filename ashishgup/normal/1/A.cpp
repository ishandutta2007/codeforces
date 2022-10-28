#include <iostream>
using namespace std;

int main()
{
    long long n;
    long long m;
    long long a;
    cin>>n>>m>>a;
    long long row=n/a;
    if(n%a!=0)
        row++;
    long long col=m/a;
    if(m%a!=0)
        col++;
    long long ans=row*col;
    cout<<ans;
    return 0;
}