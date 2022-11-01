#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n-1);
    vector<int> d(n+1,0);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&a[i]);
        d[a[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q; //highest bit,vertex
    vector<int> up(n+1,0);
    for(int i=1;i<=n;i++) up[i]=i;
    for(int i=1;i<=n;i++) if(d[i]==0) q.push({up[i],i});
    vector<pair<int,int>> edges;
    for(int i=n-2;i>=0;i--)
    {
        int bit,e=0;
        tie(bit,e)=q.top();
        q.pop();
        edges.push_back({e,a[i]});
        d[a[i]]--;
        up[a[i]]=max(up[a[i]],up[e]);
        if(d[a[i]]==0) q.push({up[a[i]],a[i]});
    }
    printf("%d\n",a[0]);
    for(pair<int,int> p:edges) printf("%d %d\n",p.first,p.second);
    return 0;
}