#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[200005];
//ll ans[200005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%lld",a+i);
    sort(a,a+n);
    for(int i=1;i<n;i++)a[i]+=a[i-1];
    for(int i=0;i<m;i++)for(int j=i+m;j<n;j+=m)a[j]+=a[j-m];
    //for(int i=1;i<n;i++)ans[i]+=ans[i-1];
    //for(int i=0;i<n;i++)a[i]*=(i/m)+1;
    printf("%lld",a[0]);
    for(int i=1;i<n;i++)
    {
        printf(" %lld",a[i]);
    }
    cout<<endl;
    //for(int i=0;i<n;i++)printf("%d\n",a[i]);cout<<endl;
    return 0;
}
/*
2 1
7 21
*/