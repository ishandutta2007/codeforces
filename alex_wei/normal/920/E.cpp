#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+2;
set <pair<int,int> > g;
set <int> d;
int n,m,cnt;
vector <int> ans[N];
bool cmp(vector <int> a,vector <int> b){return a.size()<b.size();}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g.insert({a,b});
		g.insert({b,a});
	}
	for(int i=1;i<=n;i++)
		d.insert(i);
	for(int i=1;i<=n;i++)
		if(d.count(i)){
			d.erase(i);
			queue <int> q;
			q.push(i);
			while(q.size()){
				int id=q.front();
				q.pop();
				ans[cnt].push_back(id);
				for(set <int>::iterator it=d.begin();it!=d.end();){
					int to=*it;
					if(g.find({id,to})==g.end())
						q.push(to),d.erase(it++);
					else it++;
				}
			}
			cnt++;
		}
	cout<<cnt<<endl;
	sort(ans,ans+cnt,cmp);
	for(int i=0;i<cnt;i++)
		printf("%d ",ans[i].size());
    return 0;
}