#include<bits/stdc++.h>
#define N 1001000
using namespace std;
int a[N],b[N],buf[N];
long long cnt_inv(int f[],int l,int r){
	if(r-l<=1) return 0;
	int m=(l+r)/2;
	long long ans=cnt_inv(f,l,m)+cnt_inv(f,m,r);
	int tl=l,tm=m,s=l;
	while(s<r){
		if(tl<m && (tm==r || f[tl]<=f[tm])){
			ans+=tm-m;
			buf[s++]=f[tl++];
		}
		else buf[s++]=f[tm++];
	}
	for(int i=l;i<r;i++) f[i]=buf[i]; 
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<m;i++) scanf("%d",&b[i]);
		sort(b,b+m);
		priority_queue<int> pq;
		long long ans=0;
		for(int i=0;i<n;i++){
			int l=lower_bound(b,b+m,a[i])-b;
			int r=upper_bound(b,b+m,a[i])-b;
			ans+=l;
			pq.push(l);
			pq.push(r);
			pq.pop();
		}
		for(int i=0;i<n;i++){
			ans-=pq.top();
			pq.pop();
		}
		ans+=cnt_inv(a,0,n);
		printf("%lld\n",ans);
	}
	return 0;
}