#include <bits/stdc++.h>
using namespace std;
const int N=100000;
int a[N];

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    int k=0;
    for(int i=0; i<n-1; i++)
        if(__gcd(a[i],a[i+1])>1)
            k++;
    cout<<k<<endl;
    for(int i=0,last=1; i<n; i++)
        if(__gcd(last,a[i])>1)
            cout<<1<<' ',
            last=1,
            i--;
        else
            cout<<a[i]<<' ',
            last=a[i];
    return 0;
}