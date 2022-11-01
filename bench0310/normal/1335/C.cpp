#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> v(n+1,0);
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            v[a]++;
        }
        int cnt=0;
        int m=0;
        for(int i=1;i<=n;i++)
        {
            cnt+=(v[i]>=1);
            m=max(m,v[i]);
        }
        int res=0;
        if(m<=cnt-1) res=m;
        res=max(res,min(m-1,cnt));
        printf("%d\n",res);
    }
    return 0;
}