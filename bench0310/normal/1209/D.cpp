#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	vector<int> v[n+1];
	for(int i=0;i<k;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> vis(n+1,0);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            for(int to:v[a])
            {
                if(vis[to]) continue;
                vis[to]=1;
                res++;
                q.push(to);
            }
        }
    }
    printf("%d\n",k-res);
	return 0;
}