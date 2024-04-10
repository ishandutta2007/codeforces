#include <bits/stdc++.h>
using namespace std;
const int N=100005;
struct ban
{
    int u,d;
    int i;
};
bool operator<(const ban& a,const ban& b)
{
    return a.u<b.u;
}

long long ans[N];

int n,k;
ban a[N];

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>a[i].u;
    for(int i=0;i<n;++i)
        cin>>a[i].d;
    for(int i=0;i<n;++i)
        a[i].i=i;
    sort(a,a+n);
    long long yans=0;
    multiset<int> s;
    for(int i=0;i<n;++i)
    {
        ans[a[i].i]=yans+a[i].d;
       yans+=a[i].d;
        s.insert(a[i].d);
        if(s.size()>k)
        {
            yans-=(*s.begin());
            s.erase(s.begin());
        }
    }
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}