#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        vector<int> v[n+1];
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> col(n+1,0);
        queue<int> q;
        q.push(1);
        col[1]=1;
        int one=1,two=0;
        while(!q.empty())
        {
            int e=q.front();
            q.pop();
            for(int to:v[e])
            {
                if(col[to]==0)
                {
                    col[to]=3-col[e];
                    if(col[to]==1) one++;
                    else two++;
                    q.push(to);
                }
            }
        }
        vector<int> res;
        for(int i=1;i<=n;i++)
        {
            if(one<=two&&col[i]==1) res.push_back(i);
            if(one>two&&col[i]==2) res.push_back(i);
        }
        printf("%d\n",min(one,two));
        for(int i=0;i<(int)res.size();i++) printf("%d ",res[i]);
        printf("\n");
    }
	return 0;
}