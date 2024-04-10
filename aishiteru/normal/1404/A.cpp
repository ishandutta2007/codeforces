#include<stdio.h>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int T,n,k,c0[N],c1[N];
char s[N];
int main(){
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d%d%s",&n,&k,s+1);it fl=1;
		for(i=k+1;i<=n;++i){
			if(s[i]=='?') s[i]=s[i-k];
			if((s[i]=='0'&&s[i-k]=='1')||(s[i]=='1'&&s[i-k]=='0')){fl=0;break;}
		}
		for(i=n-k;i;--i){
			if(s[i]=='?') s[i]=s[i+k];
			if((s[i]=='0'&&s[i+k]=='1')||(s[i]=='1'&&s[i+k]=='0')){fl=0;break;}
		}
		for(i=1;i<=n;++i) c0[i]=c0[i-1]+(s[i]=='0'),c1[i]=c1[i-1]+(s[i]=='1');
		for(i=k;i<=n;++i) if(c0[i]-c0[i-k]>k/2||c1[i]-c1[i-k]>k/2){fl=0;break;}
		fl?puts("YES"):puts("NO");
	}
	return 0;
}