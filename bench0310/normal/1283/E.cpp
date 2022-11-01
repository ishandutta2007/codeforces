#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    set<int> s;
    vector<int> v(n+2,0);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        s.insert(t);
        v[t]++;
    }
    int a=1,b=0;
    int now=(*s.begin());
    while(s.lower_bound(now+3)!=s.end())
    {
        now=*s.lower_bound(now+3);
        a++;
    }
    vector<bool> vis(n+2,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(v[i]>0&&vis[i+j]==0)
            {
                v[i]--;
                vis[i+j]=1;
                b++;
            }
        }
    }
    printf("%d %d\n",a,b);
    return 0;
}