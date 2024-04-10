#include <bits/stdc++.h>
using namespace std;
const int N=100003;
struct ban
{
    long long l,r;
};
bool operator<(const ban& a,const ban& b)
{
    return a.l>b.l;
}

int n;
long long a[N];
long long s[N];
vector<long long> b[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        s[i]=max(s[i-1],a[i]+1);
    for(int i=1;i<=n;++i)
    {
        long long l=i-s[i]+1;
        long long r=i;
        b[l].push_back(r);
    }
    priority_queue<ban> q;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<b[i].size();++j)
        {
            ban t;
            t.l=i;
            t.r=b[i][j];
            q.push(t);
        }
        ban t;
        do
        {
            t=q.top();
            q.pop();
        }while(t.r<i);
        s[i]=max(s[i],i-t.l+1);
        q.push(t);
    }
    long long ans=0;
    for(int i=1;i<=n;++i)
        ans+=(s[i]-a[i]-1);
    cout<<ans<<endl;
    return 0;
}