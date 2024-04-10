#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,p[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&a,&b);
		if(a+b>=n-1||abs(a-b)>1){puts("-1");continue;}
		int i=1,j=n,k=1;
		if(a>=b){
			p[k++]=i++;
			while(a||b){
				p[k++]=j--;if(!--a&&!b)break;
				p[k++]=i++;if(!--b&&!a)break;
			}
		}else{
			p[k++]=j--;
			while(a||b){
				p[k++]=i++;if(!--b&&!a)break;
				p[k++]=j--;if(!--a&&!b)break;
			}
		}
		if(p[k-1]==i-1)while(k<=n)p[k++]=i++;
		else while(k<=n)p[k++]=j--;
		for(k=1;k<=n;k++)printf("%d ",p[k]);puts("");
	}
	return 0;
}