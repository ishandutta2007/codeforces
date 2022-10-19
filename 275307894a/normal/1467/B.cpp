#include<cstdio>
#define abs(x) ((x)>0?(x):-(x))
using namespace std;
int t,n,m,k,a[300039],flag[300039],ans,maxn,now,pus;
inline int slove(int x){
	int ans=0;
	for(int i=x-1;i<=x+1;i++){
		if(a[i-1]>a[i]&&a[i]<a[i+1]) ans++;
		if(a[i-1]<a[i]&&a[i]>a[i+1]) ans++;
	}
	return ans;
}
inline int min(int x,int y){return x<y?x:y;}
#define max(a,b) ((a)>(b)?(a):(b))
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=0;maxn=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]),flag[i]=0;
		for(i=2;i<n;i++){
			if(a[i-1]>a[i]&&a[i]<a[i+1]) flag[i]=1,ans++;
			if(a[i-1]<a[i]&&a[i]>a[i+1]) flag[i]=1,ans++;
		}
		if(n<=2) printf("%d\n",ans);
		else{
			for(i=2;i<n;i++){
				now=1e9;
				if(i>2&&i<n-1) {
					pus=a[i];
					a[i]=a[i+1]+1;now=min(now,slove(i));
					a[i]=a[i+1];now=min(now,slove(i));
					a[i]=a[i+1]-1;now=min(now,slove(i));
					a[i]=a[i-1]+1;now=min(now,slove(i));
					a[i]=a[i-1];now=min(now,slove(i));
					a[i]=a[i-1]-1;now=min(now,slove(i));
					a[i]=pus;now=min(now,slove(i));
				now=-now+flag[i-1]+flag[i]+flag[i+1];
				}
				else now=flag[i-1]+flag[i]+flag[i+1];
				//if(flag[i-1]||flag[i+1]) now=2;
				maxn=max(maxn,now);
			} 
			//printf("%d %d\n",ans,maxn);
			printf("%d\n",ans-maxn);
		}
	}
}