#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    vector<int> res(n,-1);
    for(int o=0;o<=1;o++)
    {
        vector<int> v[n+1];
        vector<int> d(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if((a[i]%2)==o)
            {
                q.push(i);
                d[i]=0;
            }
            else
            {
                if(i-a[i]>=0) v[i-a[i]].push_back(i);
                if(i+a[i]<n) v[i+a[i]].push_back(i);
            }
        }
        while(!q.empty())
        {
            int e=q.front();
            q.pop();
            for(int to:v[e])
            {
                if(d[to]!=-1) continue;
                d[to]=d[e]+1;
                q.push(to);
                res[to]=d[to];
            }
        }
    }
    for(int i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
    return 0;
}