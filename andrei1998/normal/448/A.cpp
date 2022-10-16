#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a1,a2,a3,b1,b2,b3;
    cin>>a1>>a2>>a3>>b1>>b2>>b3;

    int a=a1+a2+a3;
    int b=b1+b2+b3;

    int n;
    cin>>n;

    int minim=(ceil(a/5.0)+ceil(b/10.0));

    if(minim<=n)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}