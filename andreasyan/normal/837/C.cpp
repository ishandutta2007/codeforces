#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N=102,M=1000000007;

int n,a,b;
int x[N],y[N];

bool stg(int x1,int y1,int x2,int y2)
{
    if(x1>a || x2>a || y1>b || y2>b)
        return false;
    x2=a-x2+1;
    int hx=0;
    if(x2<=x1)
        hx=(x1-x2+1);
    y2=b-y2+1;
    int hy=0;
    if(y2<=y1)
        hy=(y1-y2+1);
    return (hx*hy)==0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("tiling.in","r",stdin);
    //freopen("tiling.out","w",stdout);
    cin>>n>>a>>b;
    for(int i=0;i<n;++i)
        cin>>x[i]>>y[i];
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(stg(x[i],y[i],x[j],y[j]) || stg(y[i],x[i],x[j],y[j]) || stg(x[i],y[i],y[j],x[j]) || stg(y[i],x[i],y[j],x[j]))
                ans=max(ans,x[i]*y[i]+x[j]*y[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}