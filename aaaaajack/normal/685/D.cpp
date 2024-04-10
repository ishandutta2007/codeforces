#include<bits/stdc++.h>
#define N 100100
#define K 310
using namespace std;
int x[N<<1],y[N],iy[N],ix[N<<1];
int f[N*K];
long long ans[N];
bool cmpy(int a,int b){
	return y[a]<y[b];
}
bool cmpx(int a,int b){
	return x[a]<x[b];
}
void upd_arr(int x,int v){
	while(x<N*K){
		f[x]+=v;
		x+=x&-x;
	}
}
void upd_ans(int y,int k,int v){
	int r=0,pre=0,now;
	for(int i=y;i<y+k;i++){
		now=i;
		while(now!=pre){
			if(pre==0||(now&-now)<(pre&-pre)){
				r+=f[now];
				now-=now&-now;
			}
			else{
				r-=f[pre];
				pre-=pre&-pre;
			}
		}
		pre=i;
		ans[r]+=v;
	}
}
int main(){
	int n,k,ad;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x[i<<1],&y[i]);
		x[i<<1|1]=x[i<<1]+k;
		iy[i]=i;
		ix[i<<1]=i<<1;
		ix[i<<1|1]=i<<1|1;
	}
	sort(iy,iy+n,cmpy);
	ad=1-y[iy[0]];
	y[iy[0]]=1;
	for(int i=1;i<n;i++){
		if(y[iy[i]]+ad>y[iy[i-1]]+k){
			ad=y[iy[i-1]]+k-y[iy[i]];
		}
		y[iy[i]]+=ad;
	}
	sort(ix,ix+n+n,cmpx);
	for(int i=0;i<n+n;i++){
		int yv=y[ix[i]>>1],xv=x[ix[i]];
		upd_ans(yv,k,xv);
		if(ix[i]&1){
			upd_arr(yv,-1);
			upd_arr(yv+k,1);
		}
		else{
			upd_arr(yv,1);
			upd_arr(yv+k,-1);
		}
		upd_ans(yv,k,-xv);
	}
	for(int i=1;i<=n;i++) printf("%I64d ",ans[i]);
	return 0;
}