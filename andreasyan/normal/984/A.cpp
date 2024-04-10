#include <bits/stdc++.h>
using namespace std;
const int N=1002;

int n;
int a[N];

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    if(n%2==1)
        cout<<a[n/2]<<endl;
    else
        cout<<a[n/2-1]<<endl;
    return 0;
}