#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,ans,pd[200005],siz[200005],cnt,l[200005],r[200005];
vector <int> k[200005];
void dfs(int id)
{
	pd[id]=1;
	siz[cnt]++;
	l[cnt]=min(l[cnt],id);
	r[cnt]=max(r[cnt],id);
	for(int i=0;i<k[id].size();i++)
		if(!pd[k[id][i]])
			dfs(k[id][i]);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		k[x].push_back(y);
		k[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!pd[i]&&k[i].size()){
			cnt++,l[cnt]=1e9,dfs(i);
			if(l[cnt]<r[cnt-1])ans++;
			r[cnt]=max(r[cnt],r[cnt-1]);
			l[cnt]=max(l[cnt],r[cnt-1]+1);
			ans+=r[cnt]-l[cnt]-siz[cnt]+1;
//			cout<<r[cnt]-l[cnt]-siz[cnt]+1<<endl;
//			cout<<ans<<" "<<r[cnt]<<" "<<l[cnt]<<" "<<siz[cnt]<<endl;
		}
		
	cout<<ans<<endl;
    return 0;
}
/*
9 3
1 7
2 9
3 5
*/