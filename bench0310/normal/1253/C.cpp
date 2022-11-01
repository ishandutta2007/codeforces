#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<long long> a(n);
    for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
    sort(a.begin(),a.end());
    vector<long long> v(m,0);
    long long res=0;
    for(int i=0;i<n;i++)
    {
        v[i%m]+=a[i];
        res+=v[i%m];
        printf("%I64d%c",res," \n"[i==n-1]);
    }
    return 0;
}