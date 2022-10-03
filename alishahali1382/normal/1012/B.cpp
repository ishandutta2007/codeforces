#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, m, q, r, c;
int par[400 * 1000 + 10];

int find(int x){
	if(par[x]==x){
		return x;
	}
	return par[x]=find(par[x]);
}

void join(int x, int y){
	par[find(x)]=find(y);
}

int main(){
	//freopen("input.txt", "r", stdin);
	cin>>n>>m>>q;
	for (int i=0; i<n+m; i++){
		par[i]=i;
	}
	for (int i=0; i<q; i++){
		cin>>r>>c;
		join(r-1, n+c-1);
	}
	int ans=0;
	for (int i=0; i<n+m; i++){
		ans+=par[i]==i;
	}
	cout<<ans-1<<endl;
	return 0;
}