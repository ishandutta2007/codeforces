#include <iostream>

using namespace std;

int main()
{
    int n,v;
    cin>>n>>v;
    if (v>=n-1) cout<<n-1;
    else cout<<(n-v)*(n-v+1)/2+v-1;
    return 0;
}