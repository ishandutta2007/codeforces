#include<bits/stdc++.h>
using namespace std;
int n,K,a[16],b[16];
bitset<2010>bs[1<<16];
bool era[16];
int main(){
	scanf("%d%d",&n,&K);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	bs[0].set(0);
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++)if(i&(1<<j))bs[i]|=bs[i^(1<<j)]<<a[j];
		for(int j=2000/K;j;j--)if(bs[i].test(j*K))bs[i].set(j);
	}
	if(!bs[(1<<n)-1].test(1)){puts("NO");return 0;}
	for(int i=(1<<n)-1,k=1,t=0;i;){
		bool fd=false;
		while(!fd){
//			printf("%d,%d,%d\n",i,k,t);
			for(int j=0;j<n;j++)if((i&(1<<j))&&k>=a[j]&&bs[i^(1<<j)].test(k-a[j]))
				{i^=1<<j,b[j]=t,k-=a[j],fd=true;break;}
			if(fd)break;
			k*=K,t++;
		}
	}
	puts("YES");
	for(int i=1;i<n;i++){
		int mx=-1;
//		for(int j=0;j<n;j++)if(!era[j])printf("[%d,%d]",a[j],b[j]);puts("");
		for(int j=0;j<n;j++)if(!era[j])mx=max(mx,b[j]);
		vector<int>v;
		for(int j=0;j<n;j++)if(!era[j]&&mx==b[j])v.push_back(j);
//		if(v.size()<2)exit(0);
		assert(v.size()>=2);
		printf("%d %d\n",a[v[0]],a[v[1]]);
		a[v[0]]+=a[v[1]],era[v[1]]=true;
		while(!(a[v[0]]%K))a[v[0]]/=K,b[v[0]]--;
	}
//	for(int i=0;i<n;i++)printf("%d ",b[i]);puts("");
	
	return 0;
}