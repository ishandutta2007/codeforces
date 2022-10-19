/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,cnt=1;
char s[1001000];
struct PAM{int ch[26],fail,len,jum,diff;}t[1001000];
int f[1001000],g[1001000],F[1001000],G[1001000];
void readstr(char*s){
	static char ss[500100];
	scanf("%s",ss),n=strlen(ss);
	for(int i=0;i<n;i++)*s=ss[i],s+=2;
}
int findanc(int x,int i){
	while(i-t[x].len-1<1||s[i-t[x].len-1]!=s[i])x=t[x].fail;
	return x;
}
int main(){
	readstr(s+1),readstr(s+2),n=strlen(s+1);
	// printf("%s\n",s+1);
	t[0].fail=1,t[1].fail=0,t[1].len=-1;
	g[0]=g[1]=0x3f3f3f3f,G[0]=G[1]=-1;
	for(int i=1,las=0,now,x;i<=n;i++){
		if(!t[now=findanc(las,i)].ch[s[i]-'a']){
			t[x=++cnt].fail=t[findanc(t[now].fail,i)].ch[s[i]-'a'];
			t[x].len=t[now].len+2;
			t[now].ch[s[i]-'a']=x;
			t[x].diff=t[x].len-t[t[x].fail].len;
			t[x].jum=(t[x].diff==t[t[x].fail].diff?t[t[x].fail].jum:t[x].fail);
		}
		las=t[now].ch[s[i]-'a'];
		f[i]=0x3f3f3f3f,F[i]=-1;
		// printf("%d:\n",i);
		for(x=las;x>1;x=t[x].jum){
			// printf("<%d,%d,%d>\n",t[x].len,t[x].diff,t[t[x].jum].len);
			if(t[x].jum!=t[x].fail)
				g[x]=g[t[x].fail],G[x]=G[t[x].fail];
			else
				g[x]=0x3f3f3f3f,G[x]=-1;
			if(g[x]>f[i-t[t[x].jum].len-t[x].diff])
				g[x]=f[i-t[t[x].jum].len-t[x].diff],G[x]=i-t[t[x].jum].len-t[x].diff;
			if(f[i]>g[x]+1)
				f[i]=g[x]+1,F[i]=G[x];
		}
		if(s[i-1]==s[i]&&f[i]>f[i-2])
			f[i]=f[i-2],F[i]=i-2;
		// printf("[%d,%d]\n",f[i],F[i]);
		if(i&1)f[i]=0x3f3f3f3f,F[i]=-1;
	}
	if(f[n]==0x3f3f3f3f){puts("-1");return 0;}
	printf("%d\n",f[n]);
	for(int i=n;i;i=F[i]){
		int l=(F[i]>>1)+1,r=i>>1;
		if(l!=r)printf("%d %d\n",l,r);
	}
	return 0;
}