#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int h,n;
        scanf("%d%d",&h,&n);
        vector<int> v(n+1);
        v[0]=h+1;
        for(int i=1;i<=n;i++) scanf("%d",&v[i]);
        int now=1;
        while(v.back()==now)
        {
            v.pop_back();
            now++;
        }
        int res=0;
        int cnt=(!v.empty());
        for(int i=1;i<(int)v.size();i++)
        {
            if(v[i]+1==v[i-1]) cnt++;
            else
            {
                res+=(cnt&1);
                cnt=1;
            }
        }
        res+=(cnt&1);
        printf("%d\n",res);
    }
    return 0;
}