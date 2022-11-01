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
        vector<int> a(n);
        vector<int> pos[n+1];
        set<int> s;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]].push_back(i);
            s.insert(a[i]);
        }
        int idx=1;
        vector<int> v(n);
        vector<int> val(n+1);
        for(int o=1;o<=n;o++)
        {
            for(int p:pos[o])
            {
                v[p]=idx;
                val[idx++]=o;
            }
        }
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++) dp[v[i]]=dp[v[i]-1]+1;
        set<int> t;
        int res=n;
        for(int i=1;i<=n;i++)
        {
            if(dp[i]==1)
            {
                res=min(res,(int)(s.size()-t.size()));
                t.clear();
            }
            t.insert(val[i]);
        }
        res=min(res,(int)(s.size()-t.size()));
        printf("%d\n",res);
    }
	return 0;
}