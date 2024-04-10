/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
typedef long long ll;
typedef __int128 ii;
using namespace std;
const int N=200100;
int n,m,X[N],Y[N],A[N],B[N];
bool ban[N];
vector<int>v[N];
void construct(int x,int fi){
	int las=x;
	for(auto i:v[x])if(i!=fi){
		if(X[i]!=x)swap(X[i],Y[i]);
		++n,X[i]=n,X[n-1]=las,Y[n-1]=n,las=n;
		construct(Y[i],i);
	}
}
int sz[N],msz[N],eid,SZ;
#define iter int y;for(auto i:v[x])if(!ban[i]&&i!=fi)
void getedge(int x,int fi){
	sz[x]=1;
	iter{
		getedge(y=X[i]^Y[i]^x,i),sz[x]+=sz[y],msz[i]=max(sz[y],SZ-sz[y]);
		if(msz[i]<msz[eid])eid=i;
	}
}
void getsz(int x,int fi){sz[x]=1;iter getsz(y=X[i]^Y[i]^x,i),sz[x]+=sz[y];}
struct Line{
	ll k,b;
	Line(){}
	Line(ll K,ll B){k=K,b=B;}
	friend bool operator<(const Line&u,const Line&v){return u.k==v.k?u.b>v.b:u.k<v.k;}
	friend Line operator+(const Line&u,const Line&v){return Line(u.k+v.k,u.b+v.b);}
	ll operator()(const int&x){return k*x+b;}
	void print()const{printf("(%lldx+%lld)",k,b);}
};
bool Before(Line a,Line b,Line c,Line d){
	//check if the intersection between a and b is after that between c and d.
	return(ii)(b.b-a.b)*(d.k-c.k)>(ii)(d.b-c.b)*(b.k-a.k);
}
void Hull(vector<Line>&vec){
	vector<Line>stk;
	// printf("BEFORE:");for(auto x:vec)x.print();puts("");
	sort(vec.begin(),vec.end());
	for(auto x:vec){
		if(!stk.empty()&&stk.back().k==x.k)continue;
		while(stk.size()>=2){
			Line y=stk.back(),z=*++stk.rbegin();
			if(Before(y,z,x,y))break;
			stk.pop_back();
		}
		stk.push_back(x);
	}
	vec=stk;
	// printf("AFTER:");for(auto x:vec)x.print();puts("");
}
void getline(int x,int fi,Line l,vector<Line>&vec){
	vec.push_back(l);
	iter getline(X[i]^Y[i]^x,i,l+Line(A[i],B[i]),vec);
}
vector<Line>u,w,r;
void solve(int e){
	if(!e)return;
	getline(X[e],e,Line(A[e],B[e]),u);
	getline(Y[e],e,Line(0,0),w);
	Hull(u),Hull(w);
	// for(auto x:u)x.print();puts("");
	// for(auto x:w)x.print();puts("");
	for(int i=0,j=0;i<u.size();i++){
		r.push_back(u[i]+w[j]);
		while(j+1<w.size()&&(i+1==u.size()||Before(w[j+1],w[j],u[i+1],u[i])))
			r.push_back(u[i]+w[++j]);
	}
	u.clear(),w.clear();
	ban[e]=true;
	getsz(X[e],e),SZ=sz[X[e]],eid=0,getedge(X[e],e),solve(eid);
	getsz(Y[e],e),SZ=sz[Y[e]],eid=0,getedge(Y[e],e),solve(eid);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)scanf("%d%d%d%d",&X[i],&Y[i],&A[i],&B[i]),v[X[i]].push_back(i),v[Y[i]].push_back(i);
	construct(1,0);
	// puts("FINCONS");
	// for(int i=1;i<n;i++)printf("%d %d %dx+%d\n",X[i],Y[i],A[i],B[i]);
	for(int i=1;i<=n;i++)v[i].clear();
	for(int i=1;i<n;i++)v[X[i]].push_back(i),v[Y[i]].push_back(i);
	msz[eid=0]=SZ=n,getedge(1,0),solve(eid);
	r.emplace_back(0,0);
	Hull(r);
	for(int i=0,j=0;i<m;i++){
		for(;j+1<r.size()&&r[j](i)<=r[j+1](i);j++);
		printf("%lld ",r[j](i));
	}
	return 0;
}