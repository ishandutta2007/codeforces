#include <bits/stdc++.h>
using namespace std;
char a[1000005],b[1000005],c[1];
int n,cost;
int main()
{
    int i;
    cin >> n >> a >> b;
    for (i=0;i<=n-2;i++)
    {
        if (a[i]==b[i+1] && a[i+1]==b[i] && a[i]!=a[i+1])
        {
            cost++;
            a[i]=b[i];
            a[i+1]=b[i+1];
        }
    }
    for (i=0;i<=n-1;i++)
    {
        if (a[i]!=b[i]) cost++;
    }
    cout << cost;
}