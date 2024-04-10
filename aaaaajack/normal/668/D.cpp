#include<bits/stdc++.h>
#define N 1001000
using namespace std;
int t[N],a[N],id[N],val[N],x[N];
bool cmpx(int a,int b){
	return x[a]<x[b];
}
vector<int> op[N],f[N];
void add(int num,int y,int v){
	while(y<=op[num].size()){
		f[num][y-1]+=v;
		y+=y&-y;
	}
}
int sum(int num,int y){
	int r=0;
	while(y){
		r+=f[num][y-1];
		y-=y&-y;
	}
	return r;
}
int main(){
	int n,now=0;
	int av[3]={0,1,-1};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&a[i],&t[i],&x[i]);
	}
	for(int i=0;i<n;i++) id[i]=i;
	sort(id,id+n,cmpx);
	for(int i=1;i<n;i++){
		if(x[id[i]]==x[id[i-1]]) val[i]=val[i-1];
		else val[i]=val[i-1]+1;
	}
	for(int i=0;i<n;i++) x[id[i]]=val[i];
	for(int i=0;i<n;i++){
		op[x[i]].push_back(t[i]);
	}
	for(int i=0;i<=val[n-1];i++){
		sort(op[i].begin(),op[i].end());
		f[i].resize(op[i].size());
	}
	for(int i=0;i<n;i++){
		int tm=upper_bound(op[x[i]].begin(),op[x[i]].end(),t[i])-op[x[i]].begin();
		if(a[i]<=2){
			add(x[i],tm,av[a[i]]);
		}
		else{
			printf("%d\n",sum(x[i],tm));
		}
	}
	return 0;
}