#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int ans = 0,m;
vector<int> cat;

void dfs(int num, int v, int par, const vector<vector<int> > &eds){
	if(cat[v]) ++num;
	else num = 0;
	if(num > m) return;
	bool fl = 0;
	for(int c : eds[v])
		if(c != par){
			fl = 1;
			dfs(num,c,v,eds);
		}
	if(!fl)
		++ans;
}

int main(){
	int n;
	scanf("%d %d",&n,&m);
	cat.resize(n);
	vector<vector<int> > eds(n);
	rep(i,0,n) scanf("%d",&cat[i]);
	rep(i,0,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		--x,--y;
		eds[x].push_back(y), eds[y].push_back(x);
	}
	dfs(0,0,-1,eds);
	printf("%d\n",ans);
}