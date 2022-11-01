#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    //ifstream cin("input.txt");
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int p1=0,p2=0;
    for(int i=1; i<n; i++)
    {
        if(a[i]>a[p1]) p1=i;
        if(a[i]<a[p2]) p2=i;
    }
    if(p1>p2) swap(p1,p2);
    cout<<max(n-p1-1,p2);
    return 0;
}