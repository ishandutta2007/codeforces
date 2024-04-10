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
int T,n,m,X[200100],V[200100],C[200100],K;
ll pv[200100],pk[200100],sv[200100],sk[200100];
ll val[200100];
ll pt[200100],st[200100];
void mina(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&X[i],&V[i]),C[i]=X[i];
	sort(C+1,C+n+1),K=unique(C+1,C+n+1)-C-1;
	for(int i=1;i<=n;i++){
		int l=lower_bound(C+1,C+K+1,X[i]-V[i])-C-1;
		int o=lower_bound(C+1,C+K+1,X[i])-C;
		int r=lower_bound(C+1,C+K+1,X[i]+V[i])-C;
		pv[o-1]-=X[i]-V[i],pk[o-1]++;
		pv[l]+=X[i]-V[i],pk[l]--;
		val[o]+=V[i];
		sv[o+1]+=X[i]+V[i],sk[o+1]--;
		sv[r]-=X[i]+V[i],sk[r]++;
	}
	for(int i=1;i<=K;i++)sv[i]+=sv[i-1],sk[i]+=sk[i-1];
	for(int i=K;i;i--)pv[i]+=pv[i+1],pk[i]+=pk[i+1];
	for(int i=1;i<=K;i++)val[i]+=pv[i]+sv[i]+(pk[i]+sk[i])*C[i];
	// for(int i=1;i<=K;i++)printf("[%d:%lld]",C[i],val[i]);puts("");
	for(int i=1;i<=K;i++)if(val[i]>m)st[i]=pt[i]=val[i]-m;
	for(int i=1;i<=K;i++)st[i]=max(st[i],st[i-1]+C[i]-C[i-1]);
	for(int i=K;i;i--)pt[i]=max(pt[i],pt[i+1]+C[i+1]-C[i]);
	for(int i=1;i<=n;i++){
		int o=lower_bound(C+1,C+K+1,X[i])-C;
		ll num=max(st[o],pt[o]);
		printf("%d",num<=V[i]);
	}puts("");
	for(int i=0;i<=K+1;i++)pv[i]=pk[i]=sv[i]=sk[i]=val[i]=0,pt[i]=st[i]=0xc0c0c0c0c0c0c0c0;
}
int main(){
	memset(st,0xc0,sizeof(st)),memset(pt,0xc0,sizeof(pt));
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1
3 6
1 5
5 5
3 4
*/