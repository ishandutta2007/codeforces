#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> a;)
typedef vector<int> vi;
const int mx = 1e5+10;

int main(){
	int n;
	scanf("%d",&n);
	vector<vi> gr(n);
	int deg[mx] = {};
	bool gone[mx] = {};
	rep(i,0,n-1){
		int a,b;
		scanf("%d%d",&a,&b);
		--a,--b;
		gr[a].push_back(b);
		gr[b].push_back(a);
		++deg[a];
		++deg[b];
	}
	stack<int> junk;
	rep(i,0,n)
		if(deg[i] == 1 && deg[gr[i][0]] <= 2)
			junk.push(i);
	while(!junk.empty()){
		int j = junk.top();
		junk.pop();
		gone[j] = 1;
		for(int v : gr[j])
			if(!gone[v]){
				if(--deg[v] == 1){
					for(int vv : gr[v])
						if(!gone[vv]){
							if(deg[vv] <= 2)
								junk.push(v);
							break;
						}
				}
				break;
			}
	}
	int leafDeg[mx] = {};
	rep(i,0,n)
		if(!gone[i] && deg[i] == 1)
			for(int v : gr[i])
				++leafDeg[v];
	rep(i,0,n){
		if(gone[i])
			continue;
		int cnt = 0;
		for(int v : gr[i])
			if(!gone[v] && deg[v] - min(2, leafDeg[v]) > 1)
				++cnt;
		if(cnt > 2){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}