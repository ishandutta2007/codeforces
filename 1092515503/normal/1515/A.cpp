#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[110];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int sum=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
		if(sum==m){puts("NO");continue;}
		puts("YES");
		if(sum-a[n]==m)swap(a[n],a[n-1]);
		sum=0;
		for(int i=1;i<=n;i++){
			if(sum+a[i]==m)swap(a[i],a[i+1]);
			printf("%d ",a[i]),sum+=a[i];
		}puts("");
	}
	return 0;
}