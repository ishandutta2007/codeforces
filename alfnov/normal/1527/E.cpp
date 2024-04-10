#include<bits/stdc++.h>
using namespace std;
int a[35005];
int f[35005],ff[35005];
int ans=0;
int ll=1,rr=0;
deque<int>dq[35005];
void yidong(int l,int r){
	while(rr<r){
		++rr;
		if(dq[a[rr]].size()>=2)ans-=dq[a[rr]].back()-dq[a[rr]].front();
		dq[a[rr]].emplace_back(rr);
		if(dq[a[rr]].size()>=2)ans+=dq[a[rr]].back()-dq[a[rr]].front();
	}
	while(ll>l){
		--ll;
		if(dq[a[ll]].size()>=2)ans-=dq[a[ll]].back()-dq[a[ll]].front();
		dq[a[ll]].emplace_front(ll);
		if(dq[a[ll]].size()>=2)ans+=dq[a[ll]].back()-dq[a[ll]].front();
	}
	while(rr>r){
		if(dq[a[rr]].size()>=2)ans-=dq[a[rr]].back()-dq[a[rr]].front();
		dq[a[rr]].pop_back();
		if(dq[a[rr]].size()>=2)ans+=dq[a[rr]].back()-dq[a[rr]].front();
		--rr;
	}
	while(ll<l){
		if(dq[a[ll]].size()>=2)ans-=dq[a[ll]].back()-dq[a[ll]].front();
		dq[a[ll]].pop_front();
		if(dq[a[ll]].size()>=2)ans+=dq[a[ll]].back()-dq[a[ll]].front();
		++ll;
	}
}
void dsth(int l,int r,int L,int R){
	if(l>r)return;
	int mid=(l+r)>>1;
	int mn=INT_MAX,wz=L;
	for(int i=L;i<=R;++i){
		if(i>mid)continue;
		yidong(i,mid);
		if(mn>f[i-1]+ans){
			mn=f[i-1]+ans;
			wz=i;
		}
	}
	ff[mid]=mn;
	dsth(l,mid-1,L,wz);
	dsth(mid+1,r,wz,R);
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	memset(f,63,sizeof(f));
	f[0]=0;
	while(k--){
		memset(ff,63,sizeof(ff));
		dsth(1,n,1,n);
		for(int i=0;i<=n;++i)f[i]=ff[i];
	}
	printf("%d\n",f[n]);
	return 0;
}