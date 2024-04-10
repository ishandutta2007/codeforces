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
int n,p[200100],q[200100],mn[200100];
int t[200100];
priority_queue<int>pre;ll PRE;
priority_queue<int,vector<int>,greater<int> >suf;ll SUF;
void ADD(int x){while(x)t[x]++,x-=x&-x;}
int SUM(int x){int ret=0;while(x<=n)ret+=t[x],x+=x&-x;return ret;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),q[p[i]]=i;
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=SUM(q[i]),ADD(q[i]);
		if(pre.empty()||q[i]>pre.top())suf.push(q[i]),SUF+=q[i];
		else pre.push(q[i]),PRE+=q[i];
		while(pre.size()>suf.size())suf.push(pre.top()),SUF+=pre.top(),PRE-=pre.top(),pre.pop();
		while(suf.size()>pre.size())pre.push(suf.top()),PRE+=suf.top(),SUF-=suf.top(),suf.pop();
		if(i==1){puts("0");continue;}
		// printf("GUGU:%lld\n",sum);
		printf("%lld\n",sum+(1ll*pre.top()*pre.size()-PRE-1ll*pre.size()*(pre.size()-1)/2)+(SUF-1ll*pre.top()*suf.size()-1ll*suf.size()*(suf.size()+1)/2));
	}
	return 0;
}