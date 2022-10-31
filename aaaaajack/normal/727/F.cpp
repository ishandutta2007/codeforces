#include<bits/stdc++.h>
using namespace std;
long long a[1000];
long long mx[1010];
bool cmp(int i,int j){
	return a[i]<a[j];
}
int main(){
	int n,m;
	long long a[1000],b;//,x[1000];
	long long pre=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		pre+=a[i];
		mx[0]=max(-pre,mx[0]);
	}
	for(int i=1;i<=n;i++){
		long long l=-1,r=mx[i-1];
		while(l+1<r){
			long long md=(l+r)/2;
			priority_queue<long long> x;
			pre=md;
			int ans=0;
			for(int j=0;j<n;j++){
				pre+=a[j];
				x.push(-a[j]);
				if(pre<0){
					pre+=x.top();
					x.pop();
					ans++;
				}
			}
			if(ans<=i) r=md;
			else l=md;
		}
		mx[i]=r;
	}
	//for(int i=0;i<=n;i++) printf("%lld\n",mx[i]);
	for(int j=0;j<m;j++){
		scanf("%lld",&b);
		printf("%d\n",lower_bound(mx,mx+n+1,b,greater<long long>())-mx);
	}
	return 0;
}