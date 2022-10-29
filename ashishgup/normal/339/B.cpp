#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    long long m,n;
    cin>>n>>m;
    long long ans=0;
    vector<int> v(m+1);
    for(int i=1;i<=m;i++)
    {
        cin>>v[i];
    }
    int count=0;
    for(int i=1;i<m;i++)
    {
        if(v[i]>v[i+1])
        {
            count++;
        }
    }
    ans=ans+count*n;
    ans+=v[m]-1;
    cout<<ans;
    return 0;
}