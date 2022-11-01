#include <bits/stdc++.h>
using namespace std;
#define N (101*1000)
#define ll int

ll n,m,cnt,num_1,root;
vector <ll> e[N],ans;
bool a[N],mark[N];

void dfs(ll x,ll par=0)
{
	if(a[x])num_1--;
    mark[x]=1;
    ans.push_back(x);
    a[x]=!a[x];
    cnt++;
    //cout<<x<<"\n";
    for(int i=0;i<e[x].size();i++)
        if(!mark[e[x][i]])
        {
            dfs(e[x][i],x);
            ans.push_back(x),a[x]=!a[x];
            //cout<<x<<" "<<a[x]<<"\n";
        }
    if(x==root && a[x])ans.pop_back(),a[x]=!a[x];    
    if(a[x])a[x]=!a[x],a[par]=!a[par],ans.push_back(par),ans.push_back(x);      
}

int main()
{
	scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        ll v,u;
        scanf("%d%d",&v,&u);
        e[v].push_back(u);
        e[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i])num_1++;
    }
	for(int i=1;i<=n;i++)
		if(a[i])
		{
			root=i;
			dfs(i);
			break;
		}
	if(cnt!=n && num_1)return cout<<-1,0;				
    printf("%d\n",(ll)ans.size());
    for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
    return 0;
}