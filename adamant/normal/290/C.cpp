#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

#define ll long long
#define ld long double

int main(int argc, char *argv[])
{
    double n;
    cout.setf(ios::fixed);
    cout.precision(10);
    cin>>n;
    double foo=0,bar=0,baz=0,quz=1;
    double*a=new double[int(n)];
    double sum;
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    foo+=a[i];
    bar++;
    if(foo*quz==max(foo*quz,bar*baz))
    baz=foo,quz=bar;
    }
    cout<<baz/quz<<endl;
    return EXIT_SUCCESS;
}