#include <iostream>

using namespace std;
const int maxn=int(1e5)+1,maxs=int(2e9)+1;
long long p[maxn],n,s[maxn];
int main()
{
    cin>>n;
    for (int i=2;i<=n;i++) cin>>p[i];
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=2;i<=n;i++)
        if (s[i]==-1) s[i]=maxs;
    for (int i=2;i<=n;i++)
        if (s[i]!=maxs) s[p[i]]=min(s[p[i]],s[i]);
    for (int i=2;i<=n;i++)
        if (s[i]==maxs) s[i]=s[p[i]];
    long long kq=s[1];
    for (int i=2;i<=n;i++)
        if (s[i]<s[p[i]])
        {
            cout<<-1;
            return 0;
        }
        else kq=kq+s[i]-s[p[i]];
    cout<<kq;
    return 0;
}