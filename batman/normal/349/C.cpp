#include <bits/stdc++.h>
using namespace std;
long long n,a,s,m;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a,m=max(a,m),s+=a;
    cout<<max(m,(s-1)/(n-1)+1); 
    return 0;
}