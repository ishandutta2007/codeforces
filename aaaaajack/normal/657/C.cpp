#include<bits/stdc++.h>
#define N 200100
using namespace std;
int a[N];
inline int dis(int x,int r){
	return (r+5-x%5)%5;
}
inline int rg(int x,int r){
	int m=(x+dis(x,r));
	if(m<0) return (m-4)/5;
	else return m/5;
}
int main(){
	int n,k,b,c;
	long long ans=1LL<<60;
	scanf("%d%d%d%d",&n,&k,&b,&c);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	if(c*5<=b){
		long long tmp=0;
		for(int i=0;i<k-1;i++){
			tmp+=a[k-1]-a[i];
		}
		ans=min(tmp,ans);
		for(int i=k;i<n;i++){
			tmp-=(a[i-1]-a[i-k]);
			tmp+=1LL*(a[i]-a[i-1])*k;
			ans=min(tmp,ans);
		}
	}
	else{
		for(int r=0;r<5;r++){
			priority_queue<long long> pq;
			long long tmp=0;
			for(int i=0;i<n;i++){
				long long now=1LL*c*dis(a[i],r)+1LL*b*(rg(a[0],r)-rg(a[i],r));
				pq.push(now);
				tmp+=now;
				while(pq.size()>k) tmp-=pq.top(),pq.pop();
				if(pq.size()==k){
					ans=min(ans,tmp+1LL*b*k*(rg(a[i],r)-rg(a[0],r)));
				}
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}