#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int n,m,a[70010],p[70010],c[70010];
int lp[10];
bitset<70010>bs[10010],sb[10];
bool cho[70010];
vector<int>v[70100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[i]=i;
	sort(p+1,p+n+1,[](int x,int y){return a[x]<a[y];});
	if(m<a[p[n]]){puts("-1");return 0;}
	m-=a[p[n]];
	sb[0].set(0);
	sb[1].set(0);
	int t=1;
	for(int i=1;i<n;i++){
		sb[t]|=(sb[t]<<a[p[i]]);
		if(!(i%N))sb[t+1]=sb[t],lp[t++]=i;
	}
	lp[t]=n-1;
	if(!sb[t].test(m)){puts("-1");return 0;}
	for(int i=t-1;i>=0;i--){
		bs[0]=sb[i];
		for(int j=lp[i]+1;j<=lp[i+1];j++)
			bs[j-lp[i]]=bs[j-lp[i]-1]|(bs[j-lp[i]-1]<<a[p[j]]);
		for(int j=lp[i+1];j>lp[i];j--)
			if(a[p[j]]<=m&&bs[j-lp[i]-1].test(m-a[p[j]]))cho[j]=true,m-=a[p[j]];
	}
	for(int i=1,las=0;i<=n;i++){
		if(cho[i]){c[p[i]]=a[p[i]];continue;}
		if(las)v[p[i]].push_back(las);
		c[p[i]]=a[p[i]]-a[las],las=p[i];
	}
	for(int i=1;i<=n;i++){
		printf("%d %d ",c[i],v[i].size());
		for(auto x:v[i])printf("%d ",x);puts("");
	}
	return 0;
}