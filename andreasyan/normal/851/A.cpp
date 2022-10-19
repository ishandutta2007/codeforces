#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int n,k,t;
int main()
{
    cin>>n>>k>>t;
    if(t<=k)
        cout<<t<<endl;
    else if(t>=n)
        cout<<k-(t-n)<<endl;
    else
        cout<<k<<endl;
    return 0;
}