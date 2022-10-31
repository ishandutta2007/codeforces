#include<bits/stdc++.h>
#define Q 998244353
#define N 200100 
using namespace std;
long long h[2][20][N];
long long b[N];
long long solve(long long *a, int n, long long pre){
	long long ans=0;
	long long p[2]={pre,pre};
	for(int i=0;i<n;i++){
		p[i&1]+=a[i];
		p[(i&1)^1]-=a[i];
		h[i&1][0][i>>1]=a[i]*2;
		if(i>=2) h[i&1][0][i>>1]+=h[i&1][0][(i>>1)-1];
	}
	for(int t=0;t<2;t++){
		for(int j=1;j<20;j++){
			for(int r=0;r<(n+1)/2;r++){
				h[t][j][r]=h[t][0][r];
			}
			for(int r=0;r+(1<<j)<=n/2+1;r+=(1<<j)){
				sort(h[t][j]+r,h[t][j]+r+(1<<j));
			}
		}
	}
	for(int i=n;i>=0;i--){
		if(i+1<n) p[i&1]+=a[i+1]*2;
		if(p[i&1]>0) ans++;
		int k=i/2,r=0;
		while(k){
			int j=0;
			while((1<<j+1)<=k) j++;
			ans+=lower_bound(h[i&1][j]+r,h[i&1][j]+r+(1<<j),p[i&1])-(h[i&1][j]+r);
			r+=(1<<j);
			k-=(1<<j);
		}
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		long long ans=0;
		//sum p-c;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld",&b[i]);
		}
		//no >=2 jump
		ans+=solve(b,n,0);
		if(n>=3){
			long long pst=b[0]-b[1]-b[2],ped=b[n-3]+b[n-2]-b[n-1];
			//end with PPC
			ans+=solve(b,n-3,ped);
			//start with PCC
			ans+=solve(b+3,n-3,pst);
			//start with PCC end with PPC
			if(n>=6){
				ans+=solve(b+3,n-6,pst+ped);
			}
		}
		//start with PP end with CC
		if(n>=4){
			long long pre=0;
			for(int i=0;i<n;i++) pre+=b[i];
			pre-=2*(b[n-1]+b[n-2]);
			for(int i=n-3;i>=1;i--){
				if(pre>0) ans++;
				pre-=b[i]*2;
			}
		}
		printf("%lld\n",ans%Q);
	}
	return 0;
}