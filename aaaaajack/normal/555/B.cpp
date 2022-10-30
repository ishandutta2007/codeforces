#include<cstdio>
#include<algorithm>
#include<utility>
#include<queue>
#define N 200100
#define M 200100
#define x first
#define y second
#define inf 1023456789
using namespace std;
pair<long long,int> a[M];
long long l[N],r[N];
struct rg{
	int lb;
	int ub;
	int num;
	bool operator<(rg rhs)const{return ub>rhs.ub;}
}b[N];
int ans[N];
bool cmp(rg x,rg y){
	return x.lb<y.lb;
}
int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%I64d%I64d",&l[i],&r[i]);
	}
	for(i=0;i<m;i++){
		scanf("%I64d",&a[i].x);
		a[i].y=i+1;
	}
	sort(a,a+m);
	for(i=1;i<n;i++){
		b[i].lb=upper_bound(a,a+m,make_pair(l[i]-r[i-1]-1,inf))-a;
		b[i].ub=upper_bound(a,a+m,make_pair(r[i]-l[i-1],inf))-a;
		b[i].num=i;
	}
	sort(b+1,b+n,cmp);
	j=1;
	priority_queue<rg> pq;
	for(i=0;i<m;i++){
		while(j<n&&b[j].lb<=i) pq.push(b[j++]);
		if(!pq.empty()&&i<pq.top().ub){
			ans[pq.top().num]=a[i].y;
			pq.pop();
		}
	}
	if(j<n||!pq.empty()) puts("No");
	else{
		puts("Yes");
		for(i=1;i<n;i++) printf("%d ",ans[i]);
	}
	return 0;
}