#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        vector<int> p(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
            p[i]--;
        }
        vector<bool> v(n,0);
        vector<int> res(n);
        for(int o=0;o<n;o++)
        {
            if(v[o]) continue;
            int cnt=1;
            for(int i=p[o];i!=o;i=p[i]) cnt++;
            res[o]=cnt;
            v[o]=1;
            for(int i=p[o];i!=o;i=p[i])
            {
                res[i]=cnt;
                v[i]=1;
            }
        }
        for(int i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
    }
    return 0;
}