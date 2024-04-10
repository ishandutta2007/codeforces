#include<bits/stdc++.h>
using namespace std;
struct apple{
	int zz,wz;
	bool operator<(const apple &other)const{
		return zz<other.zz;
	}
}e[505];
int vist[505],hh[505];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		printf("1\n1\n");
		printf("%d\n",n-1);
		for(int j=2;j<=n;++j)printf("%d ",j);
		printf("\n%d\n",i);
		fflush(stdout);
		scanf("%d",&e[i-1].zz);
		e[i-1].wz=i;
	}
	e[n].zz=n,e[n].wz=1;
	vector<pair<int,int>>ed;
	sort(e+1,e+n+1);
	for(int i=1;i<=n;++i){
		int x=e[i].wz;
		int l=0;
		for(int j=2;j<=n;++j)if(!vist[j])
			if(j!=x)hh[++l]=j;
		if(!l)continue;
		printf("1\n1\n");
		printf("%d\n",l);
		for(int j=1;j<=l;++j)printf("%d ",hh[j]);
		printf("\n%d\n",x);
		fflush(stdout);
		int gs;
		scanf("%d",&gs);
		int L=1;
		while(gs--){
			int LL=L,RR=l;
			while(LL<=RR){
				int mid=(LL+RR)>>1;
				printf("1\n1\n");
				printf("%d\n",mid-L+1);
				for(int j=L;j<=mid;++j)printf("%d ",hh[j]);
				printf("\n%d\n",x);
				fflush(stdout);
				int tt;
				scanf("%d",&tt);
				if(tt)RR=mid-1;
				else LL=mid+1;
			}
			vist[hh[LL]]=1;
			ed.emplace_back(hh[LL],x);
			L=LL+1;
		}
	}
	printf("ANSWER\n");
	for(auto pi:ed)printf("%d %d\n",pi.first,pi.second);
	fflush(stdout);
	return 0;
}