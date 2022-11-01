#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    int f=0,s=(n+1)/2;
    for(int i=0; i<n; i++)
        if(i%2==0)
            cout<<a[f++]<<' ';
        else
            cout<<a[s++]<<' ';
    return 0;
}