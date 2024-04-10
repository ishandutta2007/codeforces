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
const int mod=1e9+7;
int n,cnt=1,f[1001000],g[1001000];
char s[1001000];
void prepare(){
	static char t[1001000];
	reverse(s+(n>>1),s+n);
	for(int i=0;i<(n>>1);i++)t[i<<1]=s[i];
	for(int i=0;i<(n>>1);i++)t[i<<1|1]=s[i+(n>>1)];
	for(int i=0;i<n;i++)s[i+1]=t[i];
}
struct PAM{int ch[26],fail,len,jum,diff;}t[1001000];
int findanc(int x,int i){
	while(i-t[x].len-1<1||s[i-t[x].len-1]!=s[i])x=t[x].fail;
	return x;
}
int main(){
	scanf("%s",s),n=strlen(s);
	if(n&1){puts("0");return 0;}
	prepare();
	t[1].fail=0,t[0].fail=1,t[1].len=-1;
	f[0]=1;
	for(int i=1,las=0,now,x;i<=n;i++){
		if(!t[now=findanc(las,i)].ch[s[i]-'a']){
			t[x=++cnt].fail=t[findanc(t[now].fail,i)].ch[s[i]-'a'];
			t[x].len=t[now].len+2;
			t[now].ch[s[i]-'a']=x;
			t[x].diff=t[x].len-t[t[x].fail].len;
			if(t[x].diff==t[t[x].fail].diff)t[x].jum=t[t[x].fail].jum;
			else t[x].jum=t[x].fail;
		}
		las=t[now].ch[s[i]-'a'];
		for(x=las;x>1;x=t[x].jum){
			g[x]=f[i-t[t[x].jum].len-t[x].diff];
			if(t[x].diff==t[t[x].fail].diff)(g[x]+=g[t[x].fail])%=mod;
			(f[i]+=g[x])%=mod;
		}
		if(i&1)f[i]=0;
	}
	printf("%d\n",f[n]);
	return 0;
}