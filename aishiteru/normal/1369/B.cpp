#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
int T,n;
char s[N];
int main(){ 
	scanf("%d",&T);it i,p1,p2;
	while(T--){
		scanf("%d%s",&n,s+1);
		it p1=-1,p2=-1;
		for(i=1;i<=n;++i)
			if(s[i]=='1'){p1=i-1;break;}
		for(i=n;i;--i)
			if(s[i]=='0'){p2=i+1;break;}
		if(p1==-1||p2==-1){
			for(i=1;i<=n;++i) putchar(s[i]);
			puts("");continue;
		}
		for(i=1;i<=p1;++i) putchar('0');
		if(p1+1!=p2) putchar('0');
		p2=n-p2+1;
		for(i=1;i<=p2;++i) putchar('1');
		puts("");
	}
	return 0;
}