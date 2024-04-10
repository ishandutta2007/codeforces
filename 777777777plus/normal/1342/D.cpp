#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n,k;
int m[N],c[N];

bool can(int ans,bool flag){
	int x=1,t=1;
	static vector<int> v[N];
	for(int i=0;i<ans;++i)v[i].clear();
	for(int i=0;i<n;++i){
//		if(i%(2*ans)<ans){
//			v[i%(2*ans)].push_back(m[i+1]);
//		}
//		else{
//			v[2*ans-1-(i%(2*ans))].push_back(m[i+1]);
//		}
		v[i%ans].push_back(m[i+1]);
	}
	for(int i=0;i<ans;++i){
		int sz=v[i].size();
		for(int j=sz-1;~j;--j){
			if(sz-j>c[v[i][j]])return 0;
		}
	}
	if(flag){
		printf("%d\n",ans);
		for(int i=0;i<ans;++i){
			printf("%d ",v[i].size());
			for(int j=0;j<v[i].size();++j)printf("%d ",v[i][j]);
			printf("\n");
		}
	}
	return 1;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&m[i]);
	for(int i=1;i<=k;++i)scanf("%d",&c[i]);
	sort(m+1,m+n+1);
	int l=1,r=n;
	while(l!=r){
		int mid=l+r>>1;
		if(can(mid,0))r=mid;
		else l=mid+1;
	}
	can(l,1);
}