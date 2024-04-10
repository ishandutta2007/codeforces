#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=55;
const long long INF=1000000000000000000;

int n,m;
long long a[N],b[N];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<m;++i)
        cin>>b[i];
    long long ans=INF;
    for(int i=0;i<n;++i)
    {
        long long yans=-INF;
        for(int ii=0;ii<n;++ii)
            for(int jj=0;jj<m;++jj)
                if(ii!=i)
                    yans=max(yans,a[ii]*b[jj]);
        ans=min(ans,yans);
    }
    cout<<ans<<endl;
    return 0;
}