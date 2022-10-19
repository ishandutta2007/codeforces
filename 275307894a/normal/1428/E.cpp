#include<cstdio>
#include<queue>
using namespace std;
int n,m,k,x,y,z;
long long ans,a[100039],h[100039];
inline long long chec(long long x,int y){return (x/y)*(x/y)*(y-x%y)+(x/y+1)*(x/y+1)*(x%y);}
struct yyy{
    long long ans;int num;
    bool operator <(const yyy &x) const{
    	return ans<x.ans;
    }
}tmp;
priority_queue<yyy> q;
int main(){
	register int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),ans+=a[i]*a[i];
	for(i=1;i<=n;i++) h[i]=1;
	for(i=1;i<=n;i++){
		if(a[i]!=h[i]){
			q.push((yyy){chec(a[i],h[i])-chec(a[i],h[i]+1),i});
		}
	}
	for(i=1;i<=k-n;i++){
		tmp=q.top();
		q.pop();
		ans-=tmp.ans;
		h[tmp.num]++;
		if(h[tmp.num]!=a[tmp.num]){
			q.push((yyy){chec(a[tmp.num],h[tmp.num])-chec(a[tmp.num],h[tmp.num]+1),tmp.num});
		}
	}
	printf("%lld\n",ans);
}