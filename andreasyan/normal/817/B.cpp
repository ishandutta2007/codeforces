#include <bits/stdc++.h>
using namespace std;
const long long N=200005;
const long long INF=1000000000;

int n;
long long a[N];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("name.in","r",stdin);
    //freopen("name.out","w",stdout);
    cin>>n;
    map<long long,long long> l,r;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        r[a[i]]++;
    }
    sort(a,a+n);
    long long ans=0;
    for(int i=0;i<n;++i)
    {
        r[a[i]]--;
        if(a[i]==a[1])
            ans+=(l[a[0]]*r[a[2]]);
        l[a[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}