#include <bits/stdc++.h>
using namespace std;
long long n,s,a[200005];
int main()
{
    int i;
    cin >> n >> s;
    for (i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    a[n+1]=2000000000;
    a[0]=-2000000000;
    int mid=n/2+1;
    long long cost=0;
    //cout << a[1] << endl;
    int mmrmid=mid;
    if (a[mid]<s)
    {
        while (a[mmrmid]<s)
        {
            cost+=s-a[mmrmid];
            mmrmid++;
        }
    }
    else
    {
        while (a[mid]>s)
        {
            cost+=a[mid]-s;
            mid--;
        }
    }
    cout << cost;
}