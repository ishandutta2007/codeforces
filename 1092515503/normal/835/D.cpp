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
typedef long long ll;
int n,K,m,cnt=1;
char s[100100];
struct PAM{int ch[52],fail,len;}t[100100];
int findanc(int x,int i){
	while(i-t[x].len-1<0||s[i-t[x].len-1]!=s[i])x=t[x].fail;
	return x;
}
vector<int>v[100100];
int sum[100100],dep[100100];
long long res[100100];
int buc[100100];
void dfs(int x){
	if(x>=2){
		dep[x]=dep[buc[t[x].len>>1]]+1;
		buc[t[x].len]=x;
	}
	for(auto y:v[x])dfs(y);
	buc[t[x].len]=0;
}
int main(){
	scanf("%s",s);n=strlen(s);
	for(int i=0;i<n;i++)s[i]-='a';
	// for(int i=0;i<n;i++)printf("%d ",s[i]);puts("");
	t[0].fail=1,t[1].fail=0,t[1].len=-1;
	for(int i=0,las=0,now;i<n;i++){
		if(!t[now=findanc(las,i)].ch[s[i]]){
			t[++cnt].fail=t[findanc(t[now].fail,i)].ch[s[i]];
			t[now].ch[s[i]]=cnt;
			t[cnt].len=t[now].len+2;
		}
		las=t[now].ch[s[i]];
		sum[las]++;
	}
	for(int i=cnt;i>=2;i--)sum[t[i].fail]+=sum[i],v[t[i].fail].push_back(i);
	dfs(0),dfs(1);
	for(int i=2;i<=cnt;i++)res[dep[i]]+=sum[i];
	for(int i=n;i;i--)res[i]+=res[i+1];
	for(int i=1;i<=n;i++)printf("%lld ",res[i]);
	return 0;
}