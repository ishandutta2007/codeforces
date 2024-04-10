#include<bits/stdc++.h>
#define N 500100
#define Q 998244353
using namespace std;
long long e0[N],full[N];
int a[N],p2[N];
struct cond{
	int l,r,x;
	bool operator<(cond rhs)const{return l<rhs.l||l==rhs.l&&r>rhs.r;}
}v[N];
int main(){
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	p2[0]=1;
	for(int i=1;i<=n;i++) p2[i]=p2[i-1]*2%Q;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&v[i].l,&v[i].r,&v[i].x);
	}
	sort(v,v+m);
	long long ans=1;
	for(int t=0;t<k;t++){
		vector<int> stk;
		for(int i=1;i<=n;i++) a[i]=0;
		for(int i=0;i<m;i++){
			if(v[i].x&(1<<t)){
				a[v[i].r+1]+=-1;
				a[v[i].l]+=1;
			}
			else{
				while(!stk.empty()&&v[stk.back()].r>=v[i].r) stk.pop_back();
				stk.push_back(i);
			}
		}
		for(int i=1;i<=n;i++) a[i]+=a[i-1];
		for(int i=1;i<=n;i++){
			if(a[i]) a[i]=0;
			else a[i]=1;
			a[i]+=a[i-1];
		}
		a[n+1]=a[n]+1;
		//a: prefix sum of free positions
		int tl=0,tr=0;
		full[0]=1;
		e0[0]=0;
		for(int i=1;i<=n+1;i++){
			e0[i]=e0[i-1];
			while(tr<stk.size() && v[stk[tr]].r<i) tr++;
			if(a[i]>a[i-1]){
				int pre;
				if(tr>0) pre=v[stk[tr-1]].r;
				else pre=0;
				e0[i]+=p2[a[i-1]-a[pre]]*full[pre]%Q;
				e0[i]%=Q;
			}
			if(tl<stk.size()&&i==v[stk[tl]].r){
				full[i]=(e0[i]-e0[v[stk[tl]].l-1]+Q)%Q;
				tl++;
			}
		}
		long long tmp=(e0[n+1]-e0[n]+Q)%Q;
		//printf("%lld\n",tmp);
		ans=ans*tmp%Q;
	}
	printf("%lld\n",ans);
	return 0;
}