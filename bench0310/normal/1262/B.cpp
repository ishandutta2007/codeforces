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
        vector<int> p(n,0);
        vector<int> q(n);
        vector<int> v(n+1,0);
        vector<int> t;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&q[i]);
            if(i==0||q[i]!=q[i-1])
            {
                p[i]=q[i];
                v[p[i]]=1;
            }
        }
        for(int i=n;i>=1;i--) if(v[i]==0) t.push_back(i);
        for(int i=0;i<n;i++)
        {
            if(p[i]==0)
            {
                p[i]=t.back();
                t.pop_back();
            }
        }
        bool ok=1;
        int m=0;
        for(int i=0;i<n;i++)
        {
            m=max(m,p[i]);
            if(m!=q[i]) ok=0;
        }
        if(ok) for(int i=0;i<n;i++) printf("%d%c",p[i]," \n"[i==n-1]);
        else printf("-1\n");
    }
    return 0;
}