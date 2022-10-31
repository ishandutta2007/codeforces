#include<cstdio>
#include<queue>
#include<utility>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define N 200100
using namespace std;
int lcp[N],dif[N],nxt[N],pre[N],id[N];
bool del[N];
string s[N];
bool cmp(int i,int j){
	return s[i]<s[j];
}
int main(){
	priority_queue<pair<int,pair<int,int> > > pq;
	vector<pair<int,int> > vec;
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s[i];
		id[i]=i;
		s[i].push_back('0');
	}
	for(int i=n;i<n*2;i++){
		cin>>s[i];
		id[i]=i;
		s[i].push_back('1');
	}
	sort(id,id+n*2,cmp);
	sort(s,s+n*2);
	for(int i=1;i<n*2;i++){
		for(lcp[i]=0;lcp[i]<s[i].size()&&lcp[i]<s[i-1].size()&&s[i][lcp[i]]==s[i-1][lcp[i]];lcp[i]++);
		nxt[i-1]=i;
		pre[i]=i-1;
		pq.push(make_pair(lcp[i],make_pair(i-1,i)));
	}
	nxt[n*2-1]=-1;
	pre[0]=-1;
	while(!pq.empty()){
		auto tmp=pq.top();
		int v=tmp.first,x=tmp.second.first,y=tmp.second.second;
		pq.pop();
		if(!del[x]&&!del[y]&&s[x].back()!=s[y].back()){
			vec.push_back(make_pair(x,y));
			ans+=v;
			del[x]=del[y]=true;
			int ny=nxt[y],px=pre[x];
			if(ny>=0) pre[ny]=px;
			if(px>=0) nxt[px]=ny;
			if(px>=0&&ny>=0){
				lcp[ny]=min(lcp[ny],min(lcp[y],lcp[x]));
				pq.push(make_pair(lcp[ny],make_pair(px,ny)));
			}
		}
	}
	printf("%d\n",ans);
	for(int i=0;i<vec.size();i++){
		if(id[vec[i].first]<n){
			printf("%d %d\n",id[vec[i].first]+1,id[vec[i].second]-n+1);
		}
		else{
			printf("%d %d\n",id[vec[i].second]+1,id[vec[i].first]-n+1);
		}
	}
	return 0;
}