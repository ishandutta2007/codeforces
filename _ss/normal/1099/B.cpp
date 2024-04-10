#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int t=sqrt(n);
    int t2=t;
    if (t*t2<n) t++;
    if (t*t2<n) t2++;
    cout<<t+t2;
    return 0;
}