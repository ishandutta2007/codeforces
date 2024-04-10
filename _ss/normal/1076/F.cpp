#include <iostream>

using namespace std;

int main()
{
    long long n,k,a[300001],b[300001],ta,tb,ka,kb;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    int sa=0,sb=0;
    for (int i=1;i<=n;i++)
    {
        ta=a[i];
        tb=b[i];
        if (ta>tb || (ta==tb && sa>0) )
        {
            sb=0;
            if (sa>0)
            {
                ta=ta-k+sa;
                tb=tb-1;
            }
            if (ta>tb*k+k)
            {
                cout<<"NO";
                return 0;
            }
            ka=ta/k;
            if (ta%k>0) ka++;
            if (ka-1==tb) sa=(ta-1)%k+1; else
            if (ka-1<tb) sa=0;
        }
        else
        {
            sa=0;
            if (sb>0)
            {
                tb=tb-k+sb;
                ta=ta-1;
            }
            if (tb>ta*k+k)
            {
                cout<<"NO";
                return 0;
            }
            kb=tb/k;
            if (tb%k>0) kb++;
            if (kb-1==ta) sb=(tb-1)%k+1; else
            if (kb-1<ta) sb=0;
        }
    }
    cout<<"YES";
    return 0;
}