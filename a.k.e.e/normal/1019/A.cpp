#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=3005;
const ll INF=1ll<<60;

int n,m,cur[MAXN];
vector<int> s[MAXN];
ll sum[MAXN][MAXN];
priority_queue<pii,vector<pii>,greater<pii> > pq;

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int x,y,cnt=0,tmp;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d%d",&x,&y);
    	if(x==1)cnt++;
    	else s[x].push_back(y);
    }
    for(int i=2;i<=m;i++)
    {
    	if(!s[i].size())continue;
    	sort(s[i].begin(),s[i].end());
    	sum[i][0]=s[i][0];
    	for(int j=1;j<s[i].size();j++)
    		sum[i][j]=sum[i][j-1]+s[i][j];
    }
    ll res=INF,ans;
    for(int i=max(cnt,1);i<=n;i++)
    {
    	while(!pq.empty())pq.pop();
    	memset(cur,0,sizeof(cur));
    	ans=0;tmp=cnt;
    	for(int j=2;j<=m;j++)
    		if(s[j].size()>=i)
    		{
    			ans+=sum[j][s[j].size()-i];
				cur[j]=s[j].size()-i+1;
				tmp+=cur[j];
//cout<<"\t"<<j<<":"<<cur[j]<<" "<<sum[j][s[j].size()-i]<<endl;
    		}
    	for(int j=2;j<=m;j++)
    		if(cur[j]<s[j].size())
				pq.push(make_pair(s[j][cur[j]],j));
    	while(tmp<i)
    	{
    		if(pq.empty()){ans=INF;break;}
    		pii u=pq.top();pq.pop();
    		ans+=u.first;cur[u.second]++;
    		if(cur[u.second]<s[u.second].size())
				pq.push(make_pair(s[u.second][cur[u.second]],u.second));
			++tmp;
    	}
    	res=min(res,ans);
    	//cout<<i<<":"<<ans<<endl;
    }
    cout<<res<<endl;
    return 0;
}