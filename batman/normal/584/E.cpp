#include <bits/stdc++.h>
using namespace std;

#define N (2222)
int n,a[N],b,in[N],in2[N],ans;
vector <pair<int,int> > res;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),in[a[i]]=i;
    for(int i=1;i<=n;i++)scanf("%d",&b),a[in[b]]=i,in2[i]=in[b];
    for(int i=1;i<=n;i++)
    {
            int plc=in2[i];
            for(int j=plc-1;j>=i;j--)
                    if(a[j]>=plc)
                                ans+=plc-j,res.push_back({j,plc}),in2[a[j]]=plc,in2[i]=j,swap(a[j],a[plc]),plc=j;
    }      
    cout<<ans<<"\n"<<res.size()<<"\n";
    for(int i=0;i<res.size();i++)printf("%d %d\n",(int)res[i].first,(int)res[i].second);
    
    return 0;
}