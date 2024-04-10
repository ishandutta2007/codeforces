#include<cstdio>
#include<queue>
#include<algorithm>
#define N 100100
using namespace std;
struct data{
	long long h;
	int a;
	int f;
	int die;
	static int m;
	void count_die(){
		if(1LL*(m-1)*a+f<=h) die=m+1;
		else if(h/a+1<m) die=h/a+1;
		else die=m;
	}
	bool operator<(data rhs)const{return die>rhs.die;}
}bamboo[N];
int data::m;
int n,p,k;
bool check(long long ans){
	priority_queue<data> pq;
	for(int i=0;i<n;i++){
		bamboo[i].h=ans-bamboo[i].a;
		bamboo[i].count_die();
		pq.push(bamboo[i]);
	}
	for(int i=1;i<=data::m;i++){
		for(int j=0;j<k;j++){
			data tmp=pq.top();
			pq.pop();
			tmp.h+=p;
			tmp.count_die();
			pq.push(tmp);
		}
		if(pq.top().die<=i){
			return false;
		}
	}
	return true;
}
long long bs(long long l,long long r){
	long long s=1LL<<45;
	while(s){
		if(r-s<l){
			s>>=1;
			continue;
		}
		if(check(r-s)) r-=s;
		s>>=1;
	}
	return r;
}
int main(){
	scanf("%d%d%d%d",&n,&data::m,&k,&p);
	int i;
	long long mx=0,mn=1023456789;
	for(i=0;i<n;i++){
		scanf("%d%d",&bamboo[i].f,&bamboo[i].a);
		mx=max(mx,1LL*bamboo[i].a*data::m+bamboo[i].f);
		mn=min(mn,(long long)bamboo[i].a);
	}
	printf("%I64d\n",bs(mn,mx));
	return 0;
}