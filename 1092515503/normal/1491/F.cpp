#include<bits/stdc++.h>
using namespace std;
int T,n;
int QUERY(int l1,int r1,int l2,int r2){
	printf("? %d %d\n",r1-l1+1,r2-l2+1),fflush(stdout);
	for(int i=l1;i<=r1;i++)printf("%d ",i);puts(""),fflush(stdout);
	for(int i=l2;i<=r2;i++)printf("%d ",i);puts(""),fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int two;
		for(int i=2;i<=n;i++)if(QUERY(1,i-1,i,i)){two=i;break;}
		int l=1,r=two-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(QUERY(1,mid,two,two))r=mid;
			else l=mid+1;
		}
		vector<int>v;
		for(int i=1;i<two;i++)if(i!=r)v.push_back(i);
		for(int i=two+1;i<=n;i++)if(!QUERY(two,two,i,i))v.push_back(i);
		printf("!");printf(" %d",v.size());
		for(auto x:v)printf(" %d",x);puts("");fflush(stdout);
	}
	return 0;
}