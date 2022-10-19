#include<bits/stdc++.h>
using namespace std;
int T,n,s1,s2;
char s[200100];
char r1[200100],r2[200100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1),s1=s2=0;
		int c1=0;
		for(int i=1;i<=n;i++)c1+=(s[i]=='1');
		if(c1&1){puts("NO");continue;}
		c1>>=1;
		bool ok=true;
		r1[n+1]=r2[n+1]=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				if(c1)r1[i]=r2[i]='(',c1--,s1++,s2++;
				else r1[i]=r2[i]=')',s1--,s2--;
			}else{
				if(s1>=s2)r1[i]=')',r2[i]='(',s1--,s2++;
				else r1[i]='(',r2[i]=')',s1++,s2--;
			}
			if(s1<0||s2<0){ok=false;break;}
		}
		if(!ok){puts("NO");continue;}
		puts("YES");
		printf("%s\n%s\n",r1+1,r2+1);
	}
	return 0;
}