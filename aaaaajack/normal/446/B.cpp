#include<cstdio>
#include<queue>
#define N 1001000
using namespace std;
long long a[1010]={0},b[1010]={0},dpn[N]={0},dpm[N]={0};
int main(){
	int n,m,k,p,x,i,j,t;
	long long ans;
	priority_queue<long long> pqn,pqm;
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&x);
			a[i]+=x;
			b[j]+=x;
		}
	}
	for(i=0;i<n;i++) pqn.push(a[i]);
	for(j=0;j<m;j++) pqm.push(b[j]);
	for(i=1;i<=k;i++){
		dpn[i]=dpn[i-1]+pqn.top();
		pqn.push(pqn.top()-p*m);
		pqn.pop();
		dpm[i]=dpm[i-1]+pqm.top();
		pqm.push(pqm.top()-p*n);
		pqm.pop();
	}
	ans=dpn[k];
	for(i=0;i<k;i++){
		if(dpn[i]+dpm[k-i]-1LL*i*(k-i)*p>ans){
			ans=dpn[i]+dpm[k-i]-1LL*i*(k-i)*p;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}