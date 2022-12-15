#include <stdio.h>
#include <vector>
 
int n,temp[1000001];
std::vector<int> adj[1000001];

int sub_temp[1000001], st, idx;
bool flag;

int DFS1(int node){
	for(auto &it:adj[node]) {
		sub_temp[node]+=DFS1(it);
	}
	sub_temp[node]+=temp[node];
	return sub_temp[node];
}

int DFS2(int node){
	int cnt=0;
	for(auto &it:adj[node]) {
		int val=DFS2(it);
		cnt+=val;
	}
	if(cnt>=2 && idx==0) 
		idx=node;
	if(sub_temp[node]==st*2 && cnt>=1 && idx==0 && node!=adj[0][0]) {
		idx=node;
		flag=true;
	}
	if(sub_temp[node]==st)
		cnt|=1;
	
	return cnt;
}

bool Find(int node)
{
	if(sub_temp[node]==st)  {
		printf("%d ",node);
		return true;
	}
	for(auto &it:adj[node]) {
		if(Find(it)) return true;
	}
	return false;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  {
		int pa;
		scanf("%d %d", &pa, temp+i);
		adj[pa].push_back(i);
	}

	DFS1(adj[0][0]);
	if(sub_temp[adj[0][0]]%3) {
		printf("-1\n");
		return 0;
	}
	st=sub_temp[adj[0][0]]/3;
	DFS2(adj[0][0]);
	if(idx==0) {
		printf("-1\n");
		return 0;
	}

	if(flag) {
		printf("%d ",idx);
		for(auto &it:adj[idx]) {
			if(Find(it))break;
		}
	}
	else {
		int cnt=0;
		for(auto &it:adj[idx]) {
			if(Find(it))
				cnt++;
			if(cnt>=2) break;
		}
	}
	
	return 0;
}