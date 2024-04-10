#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
long long a[N];

long long hp[N],hs[N];

long long p[N],s[N];
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    p[0]=a[0];
    for(int i=1;i<n;++i)
        p[i]=p[i-1]+a[i];
    for(int i=n-1;i>=0;--i)
        s[i]=s[i+1]+a[i];
    for(int i=0;i<n-1;++i)
    {
        if(p[i]==s[i+1])
        {
            cout<<"YES"<<endl;
            return 0;
        }
        long long dif=abs(p[i]-s[i+1]);
        if(dif%2==1)
            continue;
        dif/=2;
        if(p[i]>s[i+1])
        {
            hp[i]=dif;
        }
        else
        {
            hs[i+1]=dif;
        }
    }
    set<long long> s;
    for(int i=0;i<n;++i)
    {
        s.insert(a[i]);
        if(s.find(hp[i])!=s.end())
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    s.clear();
    for(int i=n-1;i>=0;--i)
    {
        s.insert(a[i]);
        if(s.find(hs[i])!=s.end())
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(a[i]==(p[n-1]-a[i]))
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}