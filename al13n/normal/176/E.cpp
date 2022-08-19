#pragma comment(linker,"/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <iomanip>
#include <sstream>
#include <stack>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;

inline int mymax(int a,int b){
	return a<b?b:a;
}
inline int mymin(int a,int b){
	return a>b?b:a;
}
inline lng mymax(lng a,lng b){
	return a<b?b:a;
}
inline lng mymin(lng a,lng b){
	return a>b?b:a;
}

int tree[1000000];

void setval(int p,int v,int a,int b,int k){
	if(b==a+1){
		tree[k]=v;
		return;
	}
	int c=(a+b)/2;
	if(p<c)
		setval(p,v,a,c,k*2+1);
	else
		setval(p,v,c,b,k*2+2);
	tree[k]=tree[k*2+1]+tree[k*2+2];
}

int getsum(int l,int r,int a,int b,int k){
	if(l==r)
		return 0;
	if(a==l&&b==r)
		return tree[k];
	int c=(a+b)/2;
	if(r<=c)
		return getsum(l,r,a,c,k*2+1);
	if(l>=c)
		return getsum(l,r,c,b,k*2+2);
	return getsum(l,c,a,c,k*2+1)+getsum(c,r,c,b,k*2+2);
}

int min1(int l,int r,int a,int b,int k){
	if(!tree[k])
		return -1;
	if(b==a+1)
		return a;
	int c=(a+b)/2;
	if(r<=c)
		return min1(l,r,a,c,k*2+1);
	if(l>=c)
		return min1(l,r,c,b,k*2+2);
	if(tree[k*2+1]){
		int t=min1(l,c,a,c,k*2+1);
		if(t!=-1)
			return t;
	}
	return min1(c,r,c,b,k*2+2);
}

int max1(int l,int r,int a,int b,int k){
	if(!tree[k])
		return -1;
	if(b==a+1)
		return a;
	int c=(a+b)/2;
	if(r<=c)
		return max1(l,r,a,c,k*2+1);
	if(l>=c)
		return max1(l,r,c,b,k*2+2);
	if(tree[k*2+2]){
		int t=max1(c,r,c,b,k*2+2);
		if(t!=-1)
			return t;
	}
	return max1(l,c,a,c,k*2+1);
}

vector<PII> gr[110000];
int unind[110000];
int ind[110000];
int iend[110000];
int jmp[110000][20];
lng jmw[110000][20];
int dep[110000];
int n;
int curind;

void dfs(int v,int pr,int pw,int d){
	unind[curind]=v;
	ind[v]=curind++;
	jmp[v][0]=pr;
	jmw[v][0]=pw;
	dep[v]=d;
	forv(i,gr[v]){
		int p=gr[v][i].X;
		if(p==pr)
			continue;
		dfs(p,v,gr[v][i].Y,d+1);
	}
	iend[v]=curind;
}

int todep(int a,int d){
	for(int i=19;i>=0;--i)
		if(dep[jmp[a][i]]>=d)
			a=jmp[a][i];
	return a;
}

lng todew(int a,int d){
	lng r=0;
	for(int i=19;i>=0;--i){
		if(dep[jmp[a][i]]>=d){
			r+=jmw[a][i];
			a=jmp[a][i];
		}
	}
	return r;
}

lng togw(int &a,int s){
	lng r=0;
	for(int i=19;i>=0;--i){
		int t=jmp[a][i];
		if(getsum(ind[t],iend[t],0,n,0)==s){
			r+=jmw[a][i];
			a=t;
		}
	}
	r+=jmw[a][0];
	a=jmp[a][0];
	return r;
}

int lca(int a,int b){
	int d=min(dep[a],dep[b]);
	a=todep(a,d);
	b=todep(b,d);
	if(a==b)
		return a;
	for(int i=19;i>=0;--i)
		if(jmp[a][i]!=jmp[b][i]){
			a=jmp[a][i];
			b=jmp[b][i];
		}
	return jmp[a][0];
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	cin>>n;
	forn(i,n-1){
		int a,b,c;
		cin>>a>>b>>c;
		--a;--b;
		gr[a].pb(mp(b,c));
		gr[b].pb(mp(a,c));
	}

	dfs(0,0,0,0);

	forn(i,19){
		forn(j,n){
			jmp[j][i+1]=jmp[jmp[j][i]][i];
			jmw[j][i+1]=jmw[jmp[j][i]][i]+jmw[j][i];
		}
	}

	int tc;
	cin>>tc;
	lng res=0;
	set<int> curs;
	forn(qqq,tc){
		char c;
		int v;
		cin>>c;
		if(c=='?'){
			cout<<res<<'\n';
		}else{
			cin>>v;
			--v;
			int cs=getsum(ind[v]+1,iend[v],0,n,0);
			int css=getsum(ind[v],iend[v],0,n,0);
			int cnt=getsum(0,n,0,n,0);
			int sv=cs?lca(unind[min1(ind[v]+1,iend[v],0,n,0)],unind[max1(ind[v]+1,iend[v],0,n,0)]):-1;
			bool out=cnt>css;
			int sg=(c=='+')?1:-1;
			if(cs&&!out){
				res+=sg*todew(sv, dep[v]);
			}
			if(out&&!cs){
				int vv=v;
				res+=sg*togw(vv,css);
				if(c=='-')
					setval(ind[v],0,0,n,0);
				if (getsum(0,n,0,n,0)==getsum(ind[vv],iend[vv],0,n,0))
					res+=sg*todew(lca(unind[min1(ind[vv],iend[vv],0,n,0)],unind[max1(ind[vv],iend[vv],0,n,0)]),dep[vv]);
				if(c=='-')
					setval(ind[v],1,0,n,0);
			}
			if(c=='+')
				curs.insert(v);
			else
				curs.erase(v);
			setval(ind[v],(c=='+')?1:0,0,n,0);
		}
	}

    return 0;
}