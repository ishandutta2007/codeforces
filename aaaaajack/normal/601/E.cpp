#include<cstdio>
#include<vector>
#include<cstring>
#define N (1<<15)
#define K 1010
using namespace std;
vector<int> seg[N<<1];
int st[N],m[N],v[N],k;
bool in[N];
bool ask[N];
const int Q=1e9+7,P=1e7+19;
void add(int u,int l,int r,int ql,int qr,int x){
	if(ql==qr) return;
	if(l==ql&&r==qr){
		seg[u].push_back(x);
	}
	else{
		int m=(l+r)/2;
		if(qr<=m) add(u<<1,l,m,ql,qr,x);
		else if(ql>=m) add(u<<1|1,m,r,ql,qr,x);
		else{
			add(u<<1,l,m,ql,m,x);
			add(u<<1|1,m,r,m,qr,x);
		}
	}
}
void solve(int u,int l,int r,int up,int pre[]){
	if(l>=up) return;
	int now[K];
	memcpy(now,pre,sizeof(now));
	for(int i=0;i<seg[u].size();i++){
		int x=seg[u][i];
		for(int j=k-m[x];j>=0;j--){
			if(now[j]<0) continue;
			else if(now[j]+v[x]>now[j+m[x]]) now[j+m[x]]=now[j]+v[x];
		}
	}
	if(l+1==r){
		int ans=0,tmp=0,mul=1;
		for(int i=1;i<=k;i++){
			if(now[i]>tmp) tmp=now[i];
			ans=(ans+1LL*tmp*mul)%Q;
			mul=1LL*mul*P%Q;
		}
		printf("%d\n",ans);
	}
	else{
		solve(u<<1,l,(l+r)/2,up,now);
		solve(u<<1|1,(l+r)/2,r,up,now);
	}
}
int main(){
	int n,cnt,q,now=0;
	scanf("%d%d",&n,&k);
	cnt=n+1;
	for(int i=1;i<=n;i++) st[i]=0,in[i]=1,scanf("%d%d",&v[i],&m[i]);
	scanf("%d",&q);
	while(q--){
		int tp,x,y;
		scanf("%d",&tp);
		if(tp==1){
			scanf("%d%d",&v[cnt],&m[cnt]);
			in[cnt]=1;
			st[cnt++]=now;
		}
		else if(tp==2){
			scanf("%d",&x);
			in[x]=0;
			add(1,0,N,st[x],now,x);
		}
		else{
			now++;
		}
	}
	for(int i=1;i<cnt;i++){
		if(in[i]) add(1,0,N,st[i],now,i);
	}
	int pre[K];
	memset(pre,-1,sizeof(pre));
	pre[0]=0;
	solve(1,0,N,now,pre);
	return 0;
}