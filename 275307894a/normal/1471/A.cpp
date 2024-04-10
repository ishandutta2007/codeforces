#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
int n,m,x;
ll sum,minx,maxx;
int get(){
	sum=minx=maxx=0;
	scanf("%d%d",&n,&m);
	while(n--){
		scanf("%d",&x);
		sum+=x;
		maxx+=(ll)(ceil(double(x)/m));
	}
	minx=(ll)(ceil(double(sum)/m));
	printf("%lld %lld\n",minx,maxx);
	return 0;
}
int main(){
	int T;scanf("%d",&T);
	while(--T)get();
	return get();
}