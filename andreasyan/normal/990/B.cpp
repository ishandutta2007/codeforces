#include <bits/stdc++.h>
using namespace std;
const int N=200005,K=1000003;

int n,k;
int a[N];
int b[K+K],p[K+K];

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<K+K;++i)
        p[i]=p[i-1]+b[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(!(p[a[i]+k]-p[a[i]]))
            ++ans;
    }
    cout<<ans<<endl;
    return 0;
}