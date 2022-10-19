#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,a[1010],res;
bool ok;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&m),a[m+1]=n+1,ok=true,res=0x3f3f3f3f;
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			if(a[i]==k)ok=false;
		}
		if(ok){printf("%d\n",0);continue;}
		sort(a+1,a+m+1);
		for(int i=1;i<=m;i++){
			if(a[i-1]+1!=a[i])res=min(res,abs(k-(a[i]-1)));
			if(a[i+1]-1!=a[i])res=min(res,abs(k-(a[i]+1)));
		}
		printf("%d\n",res);
	}
	return 0;
}