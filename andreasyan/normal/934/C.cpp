#include <iostream>
#include <algorithm>
using namespace std;
const int N=2004;

int n;
int a[N];
int p[N],s[N];
int main()
{
    cin>>n;
    bool z=true;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]!=a[1])
            z=false;
    }
    if(z)
    {
        cout<<n<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        p[i]=p[i-1];
        if(a[i]==1)
            p[i]++;
    }
    for(int i=n;i>=1;--i)
    {
        s[i]=s[i+1];
        if(a[i]==2)
            ++s[i];
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(i==3)
            cout<<"";
        int m=0, e=0;
        int maxu=0,r=i,l=i-1,ee=0,mm=0;
        for(int j=i;j<=n;++j)
        {
            if(a[j]==1)
                ++m;
            else
                ++e;
            if((m-e)>maxu)
            {
                maxu=(m-e);
                mm=m;
                r=j;
            }
        }
        e=0,m=0;
        maxu=0;
        for(int j=i-1;j>=1;--j)
        {
            if(a[j]==1)
                ++m;
            else
                ++e;
            if((e-m)>maxu)
            {
                maxu=(e-m);
                ee=e;
                l=j;
            }
        }
        ans=max(ans,mm+ee+p[l-1]+s[r+1]);
    }
    cout<<ans<<endl;
    return 0;
}