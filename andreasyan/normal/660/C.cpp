#include <iostream>
using namespace std;
const int N=300005;

int ans;
int ansl,ansr;

int n,k;
int a[N],p[N];

bool stg(int x)
{
    for(int l=1;l+x-1<=n;++l)
    {
        int r=l+x-1;
        if(x-(p[r]-p[l-1])<=k)
        {
            if(x>ans)
            {
                ans=x;
                ansl=l;
                ansr=r;
                return true;
            }
        }
    }
    return false;
}
void byn()
{
    int l=0,r=n;
    while((r-l)>=4)
    {
        int m=(l+r)/2;
        if(stg(m))
            l=m;
        else
            r=m;
    }
    for(int i=r;i>=l;--i)
        stg(i);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    byn();
    cout<<ans<<endl;
    for(int i=ansl;i<=ansr;++i)
        a[i]=1;
    for(int i=1;i<=n;++i)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}