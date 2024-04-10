#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x;
        scanf("%d%d",&n,&x);
        vector<int> one(n+1,0);
        for(int i=0;(1<<i)<=n;i++) one[i]=(1<<i);
        vector<int> p(n+1,0);
        vector<int> d(n+1,0);
        int sum=0;
        stack<int> s;
        for(int i=2;i<=n;i++)
        {
            p[i]=i/2;
            d[i]=d[i/2]+1;
            sum+=d[i];
            if(one[d[i]]!=i) s.push(i);
        }
        if(x<sum||(n*(n-1)/2)<x)
        {
            printf("NO\n");
            continue;
        }
        while(sum<x)
        {
            int a=s.top();
            s.pop();
            while(sum<x&&one[d[a]]!=0)
            {
                p[a]=one[d[a]];
                d[a]++;
                sum++;
                if(one[d[a]]==0)
                {
                    one[d[a]]=a;
                    break;
                }
            }
        }
        printf("YES\n");
        for(int i=2;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
    }
    return 0;
}