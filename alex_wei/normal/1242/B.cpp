#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=-1,pd[100005],p[100005];
vector <int> c[100005];
void bfs(int id)
{
	pd[id]=1;
	queue <int> q;
	q.push(id);
	while(q.size()){
		id=q.front();
		q.pop();
		int l=1;
		for(int i=p[1];i<=n;){
			if(!c[id].size()||*lower_bound(c[id].begin(),c[id].end(),i)!=i)
				pd[i]=1,p[l]=p[i],q.push(i);
			l=i,i=p[i];
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		c[a].push_back(b);
		c[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		sort(c[i].begin(),c[i].end()),p[i]=i+1;
	for(int i=1;i<=n;i++)
		if(!pd[i])
			bfs(i),ans++;
	cout<<ans;
    return 0;
}
/*
6 10
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
*/