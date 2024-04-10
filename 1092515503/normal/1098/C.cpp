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
int n,bc,num[100100],lim[100100],pos;ll m;
int id[100100],qaq,fa[100100],deg[100100];
int main(){
	scanf("%d%lld",&n,&m);
	if(m>(1ll*n*(n+1)>>1)){puts("No");return 0;}
	if(m<(n-1)+n){puts("No");return 0;}
	puts("Yes");
	for(bc=1;;bc++){
		int rem=n;ll now=1;
		ll tot=0;
		for(int i=1;rem;i++){
			int qwq=min(1ll*rem,now);
			tot+=1ll*i*qwq;
			rem-=qwq;
			now*=bc;
		}
		if(tot<=m)break;
	}
	// printf("GUGU:%d\n",bc);
	int rem=n;ll now=1;
	ll tot=0;
	for(int i=1;i<=n+1;i++){
		num[i]=min(1ll*rem,now);
		lim[i]=now;
		tot+=1ll*i*num[i];
		rem-=num[i];
		now=min(1ll*n,now*bc);
	}
	for(int i=1,j=i+1;i<=n&&num[i];i++)
		while(true){
			j=max(j,i+1);
			while(num[j]==lim[j])j++;
			int qwq=min(num[i]-1,lim[j]-num[j]);
			qwq=min(1ll*qwq,(m-tot)/(j-i));
			// printf("%d->%d:%d:%d,%d\n",i,j,qwq,m,tot);
			if(!qwq)break;
			num[i]-=qwq,num[j]+=qwq,tot+=1ll*(j-i)*qwq;
		}
	assert(tot==m);
	for(int i=1;i<=200;i++){
		for(int i=2;i<=n;i++)if(num[i]>1ll*num[i-1]*bc){
			int qwq=num[i]-num[i-1]*bc;
			qwq=(qwq-1)/(bc+2)+1;
			num[i]-=qwq<<1,num[i-1]+=qwq,num[i+1]+=qwq;
		}
		for(int i=n;i>=2;i--)if(num[i]>1ll*num[i-1]*bc){
			int qwq=num[i]-num[i-1]*bc;
			qwq=(qwq-1)/(bc+2)+1;
			num[i]-=qwq<<1,num[i-1]+=qwq,num[i+1]+=qwq;
		}
	}
	for(int i=1;i<=n;i++){
		id[i]=qaq+1;
		for(int j=1;j<=num[i];j++){
			fa[++qaq]=id[i-1],deg[id[i-1]]++;
			if(deg[id[i-1]]==bc)id[i-1]++;
		}
	}
	for(int j=2;j<=n;j++)printf("%d ",fa[j]);puts("");
	return 0;
}