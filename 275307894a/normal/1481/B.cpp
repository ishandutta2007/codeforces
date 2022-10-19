#include<cstdio>
using namespace std;
int n,m,x,y,z,a[100039],flag,t, k,ans; 
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);flag=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		while(1){
		    for(i=1;i<n;i++) if(a[i]<a[i+1]){a[i]++;k--;break;}
			if(i==n) break;
			if(!k){flag=1;printf("%d\n",i);break;}
		}
		if(!flag) printf("-1\n");
	}
}