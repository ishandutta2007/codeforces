#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
 
int T;
int n,m;
int a[N],b[N];
 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=m;++i)scanf("%d",&b[i]);
		int ans1=0,ans2=0,tot1=0,tot2=0;
		for(int p=1;p<=n;++p)
		if(a[p]<0&&(p==n||a[p+1]>0)){
			for(int i=1;i<=p;++i){
				int j=lower_bound(b+1,b+m+1,a[i])-b;
				if(j<=m&&b[j]==a[i])tot1++;
			}
			for(int i=m;i>=1;--i){
				int l=lower_bound(a+1,a+p+1,b[i])-a;
				if(l<=p){
					if(b[i]==a[l])tot1--;
					int cnt=p-l+1;
					int r=lower_bound(b+1,b+m+1,b[i]+cnt)-b-1;
					ans1=max(ans1,tot1+r-i+1);
				}
			}
			break;
		}
		for(int i=1;i<=n;++i)a[i]*=-1;
		for(int i=1;i<=m;++i)b[i]*=-1;
		reverse(a+1,a+n+1);
		reverse(b+1,b+m+1);
		for(int p=1;p<=n;++p)
		if(a[p]<0&&(p==n||a[p+1]>0)){
			for(int i=1;i<=p;++i){
				int j=lower_bound(b+1,b+m+1,a[i])-b;
				if(j<=m&&b[j]==a[i])tot2++;
			}
			for(int i=m;i>=1;--i){
				int l=lower_bound(a+1,a+p+1,b[i])-a;
				if(l<=p){
					if(b[i]==a[l])tot2--;
					int cnt=p-l+1;
					int r=lower_bound(b+1,b+m+1,b[i]+cnt)-b-1;
					ans2=max(ans2,tot2+r-i+1);
				}
			}
			break;
		}
		printf("%d\n",ans1+ans2);
	}
}