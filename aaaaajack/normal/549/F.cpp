#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<unordered_set>
#define N 300100
#define K 1000100
using namespace std;
int a[N],s[N],id[N],lb[N],rb[N];
bool in[N];
bool cmp(int i,int j){
	return a[i]<a[j];
}
vector<int> pos[K];
int main(){
	int i,j,n,k,ll,lr,rl,rr,tmp;
	long long ans=0;
	scanf("%d%d",&n,&k);
	pos[0].push_back(0);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=(s[i-1]+a[i])%k;
		pos[s[i]].push_back(i);
		id[i]=i;
		lb[i]=rb[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	for(i=1;i<=n;i++) a[i]%=k;
	for(i=1;i<=n;i++){
		lr=id[i]-1;
		ll=lb[lr];
		rl=id[i];
		rr=rb[rl];
		if(lr-ll<rr-rl){
			for(j=ll;j<=lr;j++){
				tmp=(s[j]+a[id[i]])%k;
				ans+=upper_bound(pos[tmp].begin(),pos[tmp].end(),rr)-lower_bound(pos[tmp].begin(),pos[tmp].end(),rl);
			}
		}
		else{
			for(j=rl;j<=rr;j++){
				tmp=(s[j]+k-a[id[i]])%k;
				ans+=upper_bound(pos[tmp].begin(),pos[tmp].end(),lr)-lower_bound(pos[tmp].begin(),pos[tmp].end(),ll);
			}
		}
		lb[rr]=ll;
		rb[ll]=rr;
	}
	printf("%I64d\n",ans-n);
	fprintf(stderr,"%.2f\n",1.0*clock()/CLOCKS_PER_SEC);
	return 0;
}