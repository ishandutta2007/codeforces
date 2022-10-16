#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int x,y,z,id;
}c[50005];
bool cmp(node a,node b){return a.x<b.x;}
bool cmp2(node a,node b){return a.y<b.y||a.y==b.y&&a.z<b.z;}
int n,x[50005],y[50005],z[50005],pd[50005],cnt;
map <int,int> mp;
vector <node> q[50005],rem;
int main()
{
	cin>>n;
//	for(int i=1;i<=n;i++)
//		cin>>x[i]>>y[i]>>z[i];
	
	for(int i=1;i<=n;i++)
		cin>>c[i].x>>c[i].y>>c[i].z,c[i].id=i;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(!mp[c[i].x])mp[c[i].x]=++cnt;
	for(int i=1;i<=n;i++)
		q[mp[c[i].x]].push_back(c[i]);
	for(int i=1;i<=cnt;i++){
		sort(q[i].begin(),q[i].end(),cmp2);
		vector <node> e;
		while(q[i].size()>1){
			int p=q[i].size()-1;
			node l=q[i][p],r=q[i][p-1];
			if(l.y==r.y)cout<<l.id<<" "<<r.id<<endl,q[i].pop_back(),q[i].pop_back();
			else e.push_back(l),q[i].pop_back();
		}
		if(q[i].size())e.push_back(q[i][0]);
		while(e.size()>1){
			int p=e.size()-1;
			node l=e[p],r=e[p-1];
			cout<<l.id<<" "<<r.id<<endl;
			e.pop_back(),e.pop_back();
		}
		if(e.size())rem.push_back(e[0]);
	}
	while(rem.size()){
		int p=rem.size()-1;
		node l=rem[p],r=rem[p-1];
		cout<<l.id<<" "<<r.id<<endl;
		rem.pop_back(),rem.pop_back();
	}
    return 0;
}