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
const int mod=51123987;
int head[2001000],eid;
struct node{char key;int next,to;}edge[4001000];
int&outedge(int x,char c){
	// printf("outedge:%d,%c ",x,c);
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].key==c)
		return /*printf("found=%d\n",edge[i].to),*/edge[i].to;
	// puts("NOT FOUND.");
	edge[eid].next=head[x],edge[eid].key=c,edge[eid].to=0,head[x]=eid;
	return edge[eid++].to;
}
struct PAM{int len,dep,fail;}t[2001000];
int n,cnt;
char s[2001000];
int findanc(int x,int i){
	while(i-t[x].len-1<0||s[i]!=s[i-t[x].len-1])x=t[x].fail;
	return x;
}
int pre[2001000],suf[2001000];
void build(int*num){
	memset(head,-1,sizeof(head)),eid=0;
	t[0].fail=1,t[1].fail=0,t[1].len=-1,cnt=1;
	for(int i=0,las=0,now;i<n;i++){
		if(!outedge(now=findanc(las,i),s[i])){
			t[++cnt].fail=outedge(findanc(t[now].fail,i),s[i]);
			t[cnt].len=t[now].len+2;
			outedge(now,s[i])=cnt;
			t[cnt].dep=t[t[cnt].fail].dep+1;
		}
		las=outedge(now,s[i]);
		num[i]=t[las].dep;
	}
}
int num,res;
int main(){
	scanf("%d%s",&n,s);
	build(pre);
	reverse(s,s+n);
	build(suf);
	reverse(suf,suf+n);
	for(int i=n-1;i>=0;i--)res=(1ll*num*pre[i]+res)%mod,(num+=suf[i])%=mod;
	printf("%d\n",((1ll*num*(num-1)>>1)+mod-res)%mod);
	return 0;
}