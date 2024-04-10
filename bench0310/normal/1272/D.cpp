#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n,0);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    vector<int> l(n,1);
    vector<int> r(n,1);
    for(int i=1;i<n;i++) l[i]=(a[i]>a[i-1]?l[i-1]+1:1);
    for(int i=n-2;i>=0;i--) r[i]=(a[i]<a[i+1]?r[i+1]+1:1);
    int res=l[n-1];
    for(int i=1;i<n-1;i++)
    {
        res=max(res,l[i]);
        if(a[i-1]<a[i+1]) res=max(res,l[i-1]+r[i+1]);
    }
    printf("%d\n",res);
    return 0;
}