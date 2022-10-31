#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N],b[N],f[N];
int main(){
	int n,m;
	bool imp=false,amb=false;
	scanf("%d%d",&n,&m);
	map<int,int> id;
	for(int i=0;i<n;i++){
		scanf("%d",&f[i]);
		if(id.count(f[i])) id[f[i]]=-1;
		else id[f[i]]=i;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
		if(!id.count(b[i])) imp=true;
		else if(id[b[i]]<0) amb=true;
		else a[i]=id[b[i]]+1;
	}
	if(imp) puts("Impossible");
	else if(amb) puts("Ambiguity");
	else{
		puts("Possible");
		for(int i=0;i<m;i++){
			printf("%d ",a[i]);
		}
	}
	return 0;
}