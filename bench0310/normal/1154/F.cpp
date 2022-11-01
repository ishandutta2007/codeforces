#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    vector<int> v(n+1,0);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    sort(v.begin(),v.end());
    vector<int> sum(k+1);
    sum[1]=v[1];
    for(int i=2;i<=k;i++) sum[i]=sum[i-1]+v[i];
    vector<int> offer(k+1);
    for(int i=1;i<=k;i++) offer[i]=0;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a<=k) offer[a]=max(offer[a],b);
    }
    vector<int> best(k+1,0);
    for(int o=1;o<=k;o++)
    {
        best[o]=1000000000;
        for(int i=1;i<=o;i++)
        {
            int cnt=best[o-i];
            cnt+=sum[o];
            if(o-i+offer[i]>0) cnt-=sum[o-i+offer[i]];
            best[o]=min(best[o],cnt);
        }
    }
    printf("%d\n",best[k]);
    return 0;
}