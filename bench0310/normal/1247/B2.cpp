#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    vector<int> v(1000001,0);
    while(t--)
    {
        int n,k,d;
        scanf("%d%d%d",&n,&k,&d);
        int a[n];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int cnt=0;
        for(int i=0;i<d;i++)
        {
            v[a[i]]++;
            if(v[a[i]]==1) cnt++;
        }
        int res=min(d,cnt);
        for(int i=d;i<n;i++)
        {
            v[a[i]]++;
            if(v[a[i]]==1) cnt++;
            v[a[i-d]]--;
            if(v[a[i-d]]==0) cnt--;
            res=min(res,cnt);
        }
        printf("%d\n",res);
        for(int i=0;i<n;i++) v[a[i]]=0;
    }
    return 0;
}