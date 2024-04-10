#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long ans=(n*n*n+5*n)/6;
    cout<<ans;
    return 0;
}