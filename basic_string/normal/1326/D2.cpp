#include<bits/stdc++.h>
using namespace std;
const int N=3e6+9;
char s[N],s2[N];
int p[N];
int main(){
//	freopen("1.in","r",stdin);
//	freopen("2.out","w",stdout);
	int T,n,m,i,j,k,u,v,w,ans,ans2,r;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s),m=strlen(s),ans=0;
		for(i=0,j=m-1;i<j;++i,--j){
			if(s[i]==s[j])ans+=2;
			else break;
		}
		if(i>=j){printf("%s\n",s);continue;}
		s2[0]=s2[1]='#',n=1;
		for(k=i;k<=j;++k){
			s2[++n]=s[k],s2[++n]='#';
		}
		s2[n+1]='$';
	//	for(i=n+1;i<n+5;++i)s2[i]=0;
		u=i,v=j,w=m;
		r=0;
		for(i=0;i<=n+1;++i)p[i]=0;
		for(i=1;i<=n;++i){
			p[i]=i<r?min(p[(m<<1)-i],r-i):1;
			while(s2[i-p[i]]==s2[i+p[i]])++p[i];
			if(i+p[i]>r)r=i+p[i],m=i;
		}
		ans2=0;
		for(i=1;i<=n;++i){
			if(i-p[i]==0&&ans2<p[i])ans2=p[i],k=i;
			if(i+p[i]==n+1&&ans2<p[i])ans2=p[i],k=i;
		}
		for(i=0;i<u;++i)putchar(s[i]);
		for(i=k-p[k]+2;i<k+p[k];i+=2)putchar(s2[i]);
		for(i=v+1;i<w;++i)putchar(s[i]);
		putchar(10);
	}
	return 0;
}/////////////