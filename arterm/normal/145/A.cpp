#include <iostream>
#include <string>

using namespace std;



int main()
{
    long n,f=0,s=0;
    string a,b;
    cin>>a>>b;
    n=a.length();
    for (long i=0; i<n; ++i)
    if (a[i]!=b[i])
    if (b[i]=='7')
    s++;
    else
    f++;
    cout<<max(f,s);
    return 0;
}