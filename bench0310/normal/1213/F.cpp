#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int p[n+1];
    int q[n+1];
	int pos[n+1];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    for(int i=1;i<=n;i++) scanf("%d",&q[i]);
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++) v.push_back({i,i});
    for(int i=1;i<n;i++)
    {
        if(pos[q[i]]>pos[q[i+1]]) v.push_back({pos[q[i+1]],pos[q[i]]});
    }
    sort(v.begin(),v.end());
    vector<int> r;
    int idx=0;
    int now;
    while(idx<(int)v.size())
    {
        now=v[idx].second;
        while(idx<(int)v.size()&&v[idx].first<=now)
        {
            now=max(now,v[idx].second);
            idx++;
        }
        r.push_back(now);
    }
    if((int)r.size()>=k)
    {
        printf("YES\n");
        vector<char> res(n+1);
        int now=1;
        int t=0;
        for(int i=(r.size()-k);i<(int)r.size();i++)
        {
            while(now<=r[i])
            {
                res[p[now]]=('a'+t);
                now++;
            }
            t++;
        }
        for(int i=1;i<=n;i++) printf("%c",res[i]);
        printf("\n");
    }
    else printf("NO\n");
	return 0;
}