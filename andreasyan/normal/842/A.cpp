#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

long long x,y,l,r,k;
int main()
{
    cin>>l>>r>>x>>y>>k;
    for(int i=x;i<=y;++i)
        if(i*k>=l && i*k<=r)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    cout<<"NO"<<endl;
    return 0;
}