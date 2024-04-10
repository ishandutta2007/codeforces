#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> l(n),r(n);
        for(int i=0;i<n;i++) scanf("%d",&l[i]);
        for(int i=0;i<n;i++) scanf("%d",&r[i]);
        reverse(l.begin(),l.end());
        int sum=0;
        for(int a:l) sum+=(a==1?-1:1);
        for(int a:r) sum+=(a==1?-1:1);
        map<int,int> m;
        m[0]=0;
        int d=0;
        for(int i=0;i<n;i++)
        {
            d+=(r[i]==1?-1:1);
            if(m.find(d)==m.end()) m[d]=i+1;
        }
        int cnt=0;
        int res=2*n;
        if(m.find(sum+cnt)!=m.end()) res=min(res,m[sum+cnt]);
        for(int i=0;i<n;i++)
        {
            cnt+=(l[i]==1?1:-1);
            if(m.find(sum+cnt)!=m.end()) res=min(res,i+1+m[sum+cnt]);
        }
        printf("%d\n",res);
    }
    return 0;
}