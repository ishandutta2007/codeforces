#include<cstdio>
#include<utility>
#include<algorithm>
#include<cstring>
#include<vector>
#define N ((1<<21)+1)
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.first<b.first) return true;
	if(a.first==b.first&&a.second>b.second) return true;
	return false;
}
pair<int,int> p[N],q[N];
int f[N]={0},g[N]={0};
void add(int *t,int x,int a){
	while(x<N){
		t[x]+=a;
		x+=x&-x;
	}
}
int sum(int *t,int x){
	int ans=0;
	while(x){
		ans+=t[x];
		x-=x&-x;
	}
	return ans;
}
int main(){
	int n,m,r=0,i,j,k,x,lb;
	long long inv[30]={0},ieq[30]={0},ans;
	scanf("%d",&n);
	for(i=0;i<(1<<n);i++){
		scanf("%d",&p[i].first);
		p[i].second=i+1;
		add(f,i+1,1);
		add(g,i+1,1);
		q[i]=p[i];
	}
	sort(p,p+(1<<n),cmp);
	sort(q,q+(1<<n));
	for(i=0;i<(1<<n);i++){
		x=p[i].second-1;
		while(x){
			lb=x&-x;
			k=-1;
			while(lb) lb>>=1,k++;
			ieq[k]+=f[x];
			x-=x&-x;
		}
		add(f,p[i].second,-1);
	}
	for(i=0;i<(1<<n);i++){
		x=q[i].second-1;
		while(x){
			lb=x&-x;
			k=-1;
			while(lb) lb>>=1,k++;
			inv[k]+=g[x];
			x-=x&-x;
		}
		add(g,q[i].second,-1);
	}
	scanf("%d",&m);
	/*printf("inv\n");
	for(i=0;i<n;i++){
		printf("%d\n",inv[i]);
	}
	printf("eq\n");
	for(i=0;i<n;i++){
		printf("%d\n",eq[i]);
	}*/
	for(i=0;i<m;i++){
		ans=0;
		scanf("%d",&x);
		r^=(1<<x)-1;
		for(j=0;j<n;j++){
			if(!(r&(1<<j))){
				ans+=inv[j];
			}
			else{
				ans+=(1LL<<(j+1))*(1LL<<j)/2*(1LL<<(n-j-1))-ieq[j];
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}