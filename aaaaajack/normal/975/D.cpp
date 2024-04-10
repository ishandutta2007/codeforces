#include<bits/stdc++.h>
#define N 300100
using namespace std;
typedef pair<long long,long long> pt;
struct point{
	int sx,vx;
	long long vy;
	bool operator<(const point& rhs)const{
		return vy<rhs.vy||vy==rhs.vy&&sx>rhs.sx;
	}
}p[N];
int f[N];
int sum(int x){
	int r=0;
	while(x){
		r+=f[x];
		x-=x&-x;
	}
	return r;
}
void upd(int x,int v){
	while(x<N){
		f[x]+=v;
		x+=x&-x;
	}
}
int main(){
	int n,sx,vx,vy,a,b;
	long long ans=0;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<n;i++){
		scanf("%d%d%lld",&p[i].sx,&p[i].vx,&p[i].vy);
		p[i].vy-=1LL*a*p[i].vx;
	}
	sort(p,p+n);
	map<int,int> s;
	int pre=0;
	for(int i=0;i<n;i++){
		if(i&&(p[i].vy!=p[i-1].vy)){
			s.clear();
			ans+=1LL*(i-pre)*(i-pre-1);
			pre=i;
		}
		ans-=2*s[p[i].vx];
		s[p[i].vx]++;
	}
	ans+=1LL*(n-pre)*(n-pre-1);
	printf("%lld\n",ans);
	return 0;
}