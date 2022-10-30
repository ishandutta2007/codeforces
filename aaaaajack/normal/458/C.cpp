#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100100
using namespace std;
struct pack{
	int a;
	int b;
	bool operator<(pack rhs)const{return b<rhs.b;}
}voter[N];
long long f[N]={},left[N]={};
vector<int> g[N],h[N];
void upd(long long *t,int x,long long y){
	while(x<N){
		t[x]+=y;
		x+=x&-x;
	}
}
long long sum(long long *t,int x){
	long long y=0;
	while(x){
		y+=t[x];
		x^=x&-x;
	}
	return y;
}
int bs(int k){
	int r=1<<20,st=0;
	while(r){
		if(st+r<N&&left[st+r]<k){
			st+=r;
			k-=left[st];
		}
		r>>=1;
	}
	return st+1;
}
int main(){
	int n,i,j,now=0;
	long long money=0,ans=(1LL<<60);
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&voter[i].a,&voter[i].b);
	}
	sort(voter+1,voter+n+1);
	for(i=1;i<=n;i++){
		upd(f,i,voter[i].b);
		upd(left,i,1);
		g[voter[i].a].push_back(i);
	}
	for(i=1;i<N;i++){
		for(j=0;j<g[i].size();j++){
			h[g[i].size()-j].push_back(g[i][j]);
		}
	}
	for(i=n;i>=1;i--){
		for(j=0;j<h[i].size();j++){
			upd(left,h[i][j],-1);
			upd(f,h[i][j],-voter[h[i][j]].b);
			money+=voter[h[i][j]].b;
			now++;
		}
		if(now>=i){
			ans=min(ans,money);
		}
		else if(bs(i-now)<N){
			ans=min(ans,money+sum(f,bs(i-now)));
		}
	}
	printf("%I64d\n",ans);
	return 0;
}