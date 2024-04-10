#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#define N 65536
using namespace std;
int deg[N],sum[N];
int main(){
	vector<pair<int,int> > v;
	int n,i;
	queue<int> q;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&deg[i],&sum[i]);
		if(deg[i]==1) q.push(i);
	}
	while(!q.empty()){
		if(deg[q.front()]==1){
			v.push_back(make_pair(q.front(),sum[q.front()]));
			deg[q.front()]--;
			deg[sum[q.front()]]--;
			sum[sum[q.front()]]^=q.front();
			q.push(sum[q.front()]);
			sum[q.front()]=0;
		}
		q.pop();
	}
	printf("%d\n",(int)v.size());
	for(i=0;i<v.size();i++){
		printf("%d %d\n",v[i].first,v[i].second);
	}
	return 0;
}