#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<int> par;

int find(int cur){
	if(par[cur] == -1) return cur;
	return par[cur] = find(par[cur]);
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	par[b] = a;
	return true;
}

struct edge{
	int u, v, w;
};

bool cmp(edge a, edge b){
	return a.w < b.w;
}

signed main(){
	int n, m; cin>>n>>m;
	vector<edge> e(m);
	for(int i = 0; i < m; i++){
		cin>>e[i].u>>e[i].v>>e[i].w; e[i].u--; e[i].v--;
	}
	vector<edge> e2(e.begin()+1, e.end());
	sort(e2.begin(), e2.end(), cmp);
	edge badEdge = e[0];
	par = vector<int>(n, -1);
	sort(e.begin(), e.end(), cmp);
	int firstSum = 0;
	int firstCnt = 0;
	
	for(int i = 0; i < m-1; i++){
		if(merge(e2[i].u, e2[i].v)){
			firstCnt++;
			firstSum += e2[i].w;
		}
	}
	
	int low = 0, high = 1e9, mid;
	while(low < high){
		
		mid = (low + high+1)/2;
		
		par = vector<int>(n, -1);
		
		//first merge the badEdge
		merge(badEdge.u, badEdge.v);
		int sum = mid;
		int cnt = 1;
		for(int i = 0; i < e2.size(); i++){
			if(merge(e2[i].u, e2[i].v)){
				cnt++;
				sum += e2[i].w;
			}
		}
		
		assert(cnt == n-1);
		if(firstCnt < n-1 || sum <= firstSum){
			low = mid;
		}else{
			high = mid-1;
		}
	} 	
	mid = (low + high + 1)/2;
	cout<<mid<<endl;
}