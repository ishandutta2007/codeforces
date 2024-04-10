#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps=1e-12;
int n,m,q,a[200100],c[200100],r[200100];
double F(int X,int R){
	if(R<0)return 0x3f3f3f3f;
	if(R>=a[X])return 0;
	return 1.0*c[X]*a[X]/(a[X]+R+1)/(a[X]+R);
}
double G(int x){return 1.0*c[x]*min(r[x],a[x])/(a[x]+min(r[x],a[x]));}
struct dat{
	double val;
	int id,lot;
	dat(int X,int Y){id=X,lot=Y,val=F(id,lot);}
	friend bool operator<(const dat&u,const dat&v){return fabs(u.val-v.val)<eps?u.id<v.id:u.val<v.val;}
};
multiset<dat>all,cho;
double res;
void Push(){
	auto it=--cho.end();
	res+=it->val;
	int x=it->id;
	all.erase(dat(x,r[x]-1)),all.insert(*it);
	cho.erase(it),cho.insert(dat(x,++r[x]));
}
void Pop(){
	auto it=all.begin();
	res-=it->val;
	int x=it->id;
	cho.erase(dat(x,r[x])),cho.insert(*it);
	all.erase(it),all.insert(dat(x,--r[x]-1));
}
void read(int &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
int main(){
	read(n),read(m),read(q);
	for(int i=1;i<=n;i++)read(c[i]);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)all.insert(dat(i,-1)),cho.insert(dat(i,0));
	while(m--)Push();
//	printf("%lf\n",res);
	for(int i=1,x,y;i<=q;i++){
		read(y),read(x);
		all.erase(dat(x,r[x]-1)),cho.erase(dat(x,r[x])),res-=G(x);
		if(y==1)a[x]++;else a[x]--;
		all.insert(dat(x,r[x]-1)),cho.insert(dat(x,r[x])),res+=G(x);
		while(cho.rbegin()->val>all.begin()->val+eps)Pop(),Push();
		printf("%.8lf\n",res);
	}
	return 0;
}