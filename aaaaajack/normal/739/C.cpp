#include<bits/stdc++.h>
#define N 300100
using namespace std;
int lu[N<<1],ld[N<<1],ru[N<<1],rd[N<<1];
long long add[N<<1],val[N<<1];
bool in[N<<1];
void rec_push(int u){
	if(u>>1){
		rec_push(u>>1);
		if(lu[u>>1]>=0) lu[u]=lu[u^1]=lu[u>>1];
		if(ru[u>>1]>=0) ru[u]=ru[u^1]=ru[u>>1];
		if(ld[u>>1]>=0) ld[u]=ld[u^1]=ld[u>>1];
		if(rd[u>>1]>=0) rd[u]=rd[u^1]=rd[u>>1];
		add[u]+=add[u>>1];
		add[u^1]+=add[u>>1];
		lu[u>>1]=ru[u>>1]=ld[u>>1]=rd[u>>1]=-1;
		add[u>>1]=0;
	}
}
int main(){
	int n,q,l,r,a,tl,tr,lp,rp;
	multiset<int> h;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%I64d",&add[n+i]);
	memset(lu,-1,sizeof(lu));
	memset(ru,-1,sizeof(ru));
	memset(ld,-1,sizeof(ld));
	memset(rd,-1,sizeof(rd));
	lu[n]=ld[n]=0;
	for(int i=n+1;i<n+n;i++){
		if(add[i]>add[i-1]) ld[i]=ld[i-1];
		else ld[i]=i-n;
		if(add[i]<add[i-1]) lu[i]=lu[i-1];
		else lu[i]=i-n;
	}
	ru[n+n-1]=rd[n+n-1]=n-1;
	for(int i=n+n-2;i>=n;i--){
		if(add[i]>add[i+1]) rd[i]=rd[i+1];
		else rd[i]=i-n;
		if(add[i]<add[i+1]) ru[i]=ru[i+1];
		else ru[i]=i-n;
	}
	for(int i=n;i<n+n;i++){
		if((i==n||add[i]>=add[i-1])&&(i==n+n-1||add[i]>=add[i+1])){
			h.insert(val[i]=rd[i]-ld[i]+1);
			in[i]=true;
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&l,&r,&a);
		l--;
		tl=n+l,tr=n+r;
		while(tl<tr){
			if(tl&1) add[tl++]+=a;
			if(tr&1) add[--tr]+=a;
			tl>>=1,tr>>=1;
		}
		if(l>0){
			rec_push(n+l);
			rec_push(n+l-1);
			rp=n+ru[n+l],lp=n+lu[n+l-1];
			if(in[lp]) h.erase(h.find(val[lp])),in[lp]=false;
			if(in[rp]) h.erase(h.find(val[rp])),in[rp]=false;
			if(add[n+l]>add[n+l-1]){
				tl=n+l,tr=n+ru[n+l]+1;
				while(tl<tr){
					if(tl&1) ld[tl++]=ld[n+l-1];
					if(tr&1) ld[--tr]=ld[n+l-1];
					tl>>=1,tr>>=1;
				}
			}
			if(add[n+l]>=add[n+l-1]){
				tl=n+l,tr=n+rd[n+l]+1;
				while(tl<tr){
					if(tl&1) lu[tl++]=l;
					if(tr&1) lu[--tr]=l;
					tl>>=1,tr>>=1;
				}
			}
		}
		if(r<n){
			rec_push(n+r);
			rec_push(n+r-1);
			rp=n+ru[n+r],lp=n+lu[n+r-1];
			if(in[lp]) h.erase(h.find(val[lp])),in[lp]=false;
			if(in[rp]) h.erase(h.find(val[rp])),in[rp]=false;
			if(add[n+r]<add[n+r-1]){
				tr=n+r,tl=n+lu[n+r-1];
				while(tl<tr){
					if(tl&1) rd[tl++]=rd[n+r];
					if(tr&1) rd[--tr]=rd[n+r];
					tl>>=1,tr>>=1;
				}
			}
			if(add[n+r]<=add[n+r-1]){
				tr=n+r,tl=n+ld[n+r-1];
				while(tl<tr){
					if(tl&1) ru[tl++]=r-1;
					if(tr&1) ru[--tr]=r-1;
					tl>>=1,tr>>=1;
				}
			}
		}
		if(l>0){
			rec_push(n+l);
			rec_push(n+l-1);
			rp=n+ru[n+l],lp=n+lu[n+l-1];
			if(add[n+l]>add[n+l-1]){
				tr=n+l,tl=n+ld[n+l-1];
				while(tl<tr){
					if(tl&1) ru[tl++]=ru[n+l];
					if(tr&1) ru[--tr]=ru[n+l];
					tl>>=1,tr>>=1;
				}
			}
			if(add[n+l]>=add[n+l-1]){
				tr=n+l,tl=n+lu[n+l-1];
				while(tl<tr){
					if(tl&1) rd[tl++]=l-1;
					if(tr&1) rd[--tr]=l-1;
					tl>>=1,tr>>=1;
				}
			}
			rec_push(lp);
			rec_push(rp);
			if(!in[rp]&&add[rp]>=add[rp-1]) h.insert(val[rp]=rd[rp]-ld[rp]+1),in[rp]=true;
			if(!in[lp]&&add[lp]>=add[lp+1]) h.insert(val[lp]=rd[lp]-ld[lp]+1),in[lp]=true;
		}
		if(r<n){
			rec_push(n+r);
			rec_push(n+r-1);
			rp=n+ru[n+r],lp=n+lu[n+r-1];
			if(add[n+r]<add[n+r-1]){
				tl=n+r,tr=n+rd[n+r]+1;
				while(tl<tr){
					if(tl&1) lu[tl++]=lu[n+r-1];
					if(tr&1) lu[--tr]=lu[n+r-1];
					tl>>=1,tr>>=1;
				}
			}
			if(add[n+r]<=add[n+r-1]){
				tl=n+r,tr=n+ru[n+r]+1;
				while(tl<tr){
					if(tl&1) ld[tl++]=r;
					if(tr&1) ld[--tr]=r;
					tl>>=1,tr>>=1;
				}
			}
			rec_push(lp);
			rec_push(rp);
			if(!in[rp]&&add[rp]>=add[rp-1]) h.insert(val[rp]=rd[rp]-ld[rp]+1),in[rp]=true;
			if(!in[lp]&&add[lp]>=add[lp+1]) h.insert(val[lp]=rd[lp]-ld[lp]+1),in[lp]=true;
		}
		printf("%d\n",*h.rbegin());
	}
	return 0;
}