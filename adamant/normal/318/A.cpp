#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

main()
{
    long long n,k;
    cin>>n>>k;
    if(k<=(n+1)/2)
    cout<<2*k-1<<endl;
    else
    cout<<(k-(n+1)/2)*2<<endl;

}