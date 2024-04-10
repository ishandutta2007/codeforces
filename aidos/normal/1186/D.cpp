#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double a[n];
    long long s=0,i,j;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s=s+floor(a[i]);
    }
    if(s<0)
    s=-s;
    for(i=0;i<n;i++)
    {
        if(abs(a[i]-floor(a[i])) > 1e-7&&s)
        {
            s--;
            cout<<floor(a[i])+1;
        }
        else
        cout<<floor(a[i]);
        cout<<endl;
    }
    
    return 0;
}