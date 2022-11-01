#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long s=0, mx=0;
    for(int i=0, l; i<n; i++)
    {
        cin >> l;
        mx=max(mx, (long long)l);
        s+=l;
    }
    cout<<2*mx-s+1;
    return 0;
}