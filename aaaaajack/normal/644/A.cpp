#include<bits/stdc++.h>
using namespace std;
int s[110][110];
int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if(n>a*b) puts("-1");
	else{
		int l=1,r=2;
		for(int i=0;i<a&&l<=n;i++){
			for(int j=i&1;j<b&&l<=n;j+=2){
				s[i][j]=l;
				l+=2;
			}
		}
		for(int i=0;i<a&&r<=n;i++){
			for(int j=(i&1)^1;j<b&&r<=n;j+=2){
				s[i][j]=r;
				r+=2;
			}
		}
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				printf("%d ",s[i][j]);
			}
			puts("");
		}
	}
	return 0;
}