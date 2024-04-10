#include<bits/stdc++.h>
using namespace std;
int f[409][409];
char s[409],t[409];
int main(){
	int T,i,j,k,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
		for(i=1;i<=m;++i){
			for(j=1,k=1;j<=n;++j){
				while(j<=n&&s[j]!=t[k])++j;
				if(j>n){
					puts("NO");
					goto ggg;
				}
				++k;
				if(k>i)break;
			}
			for(j=0;j<=n;++j){
				for(k=0;k<=i;++k){
					f[j][k]=-1e9;
				}
			}
			f[0][0]=0;
			for(j=1;j<=n;++j){
				for(k=0;k<=i;++k){
					f[j][k]=f[j-1][k];
					if(f[j-1][k]>=0&&s[j]==t[i+f[j-1][k]+1])++f[j][k];
					if(s[j]==t[k]&&k>0&&f[j][k]<f[j-1][k-1])f[j][k]=f[j-1][k-1];
				}
			}
			if(f[n][i]==m-i){
				puts("YES");
				goto ggg;
			}
		}
		puts("NO");
		ggg:;
	}
	return 0;
}//