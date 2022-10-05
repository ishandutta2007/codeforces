#include<bits/stdc++.h>
using namespace std;
vector<int>v[53];
int f[10003];
int main(){
	int m,n,i,j,k;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;++i){
		scanf("%d",&k);
		while(k--)scanf("%d",&j),v[i].push_back(j);
	}
	for(i=0;i<m;++i)for(j=i+1;j<m;++j){
		memset(f,0,sizeof(f));
		for(auto o:v[i])++f[o];
		for(auto o:v[j])++f[o];
		for(k=1;k<=n;++k)if(f[k]>1)goto _;
		puts("impossible");return 0;
		_:;
	}
	puts("possible");
	return 0;
}