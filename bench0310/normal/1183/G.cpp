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
        vector<pair<int,int>> c(n+1,make_pair(0,0));
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            c[a].first++;
            c[a].second+=b;
        }
        vector<int> v[n+1];
        for(int i=1;i<=n;i++) v[c[i].first].push_back(c[i].second);
        priority_queue<int> q;
        int res=0,cnt=0;
        for(int o=n;o>=1;o--)
        {
            for(int i=0;i<(int)v[o].size();i++) q.push(v[o][i]);
            if(q.empty()) continue;
            res+=o;
            cnt+=min(o,q.top());
            q.pop();
        }
        printf("%d %d\n",res,cnt);
    }
	return 0;
}