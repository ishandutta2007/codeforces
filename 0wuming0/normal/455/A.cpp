#include"bits/stdc++.h"
using namespace std;
long long v[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        v[t]+=t;
    }
    long long bestok=0,bestfail=0;
    for(int i=1;i<100005;i++)
    {
        long long temp=bestfail;
        bestfail=max(bestok+v[i],bestfail);
        bestok=temp;
    }
    cout<<bestfail<<endl;
    return 0;
}