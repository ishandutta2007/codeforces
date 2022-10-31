#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll 
#define P 998244353
#define fir first
#define sec second
const int N=1000005;
int T,a[N],n,cnum;
struct ky{
	int id,w;
	bool operator < (const ky&p)const{return id<p.id;}
};
set<ky> S1;
struct kyl{
	int id,w;
	bool operator < (const kyl&p)const{return w^p.w?w>p.w:id<p.id;}
};
set<kyl> S2;
int main(){ 
	scanf("%d",&T);it op;
	while(T--){
		scanf("%d",&op);
		if(op==2){
			auto p=*S1.begin();S1.erase(S1.begin()),S2.erase(S2.find((kyl){p.id,p.w}));
			printf("%d ",p.id);
		}
		if(op==3){
			auto p=*S2.begin();S2.erase(S2.begin()),S1.erase(S1.find((ky){p.id,p.w}));
			printf("%d ",p.id);
		}
		if(op==1) scanf("%d",&op),++cnum,S1.insert((ky){cnum,op}),S2.insert((kyl){cnum,op});
	}
	return 0;
}