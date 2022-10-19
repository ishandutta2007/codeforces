#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=100005;

int n,m;

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("circles.in","r",stdin);
    //freopen("circles.out","w",stdout);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(15);
    cin>>n>>m;
    long double ans=0;
    long double mz=0;
    for(int i=0;i<n;++i)
        mz+=i;
    long double pz=0;
    for(int i=0;i<=n/2;++i)
        pz+=i;
    pz*=2;
    if(n%2==0)
        pz-=(n/2);
    while(m--)
    {
        long double x,d;
        cin>>x>>d;
        ans+=((x*n));
        if(d>0)
        {
            ans+=((d*mz));
        }
        else
        {
            ans+=((d*pz));
        }
    }
    cout<<ans/n<<endl;
    return 0;
}