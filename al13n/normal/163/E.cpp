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
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
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

int tree[5000000];

void build(int a,int b,int k){
	tree[k]=0;
	if(b==a+1)
		return;
	int c=(a+b)/2;
	build(a,c,k*2+1);
	build(c,b,k*2+2);
}

void addseg(int v,int l,int r,int a,int b,int k){
	if(r<=l)
		return;
	if(l==a&&r==b){
		tree[k]+=v;
		return;
	}
	int c=(a+b)/2;
	if(r<=c)
		addseg(v,l,r,a,c,k*2+1);
	else if(l>=c)
		addseg(v,l,r,c,b,k*2+2);
	else{
		addseg(v,l,c,a,c,k*2+1);
		addseg(v,c,r,c,b,k*2+2);
	}
}

int getval(int p,int a,int b,int k){
	if(b==a+1)
		return tree[k];
	int c=(a+b)/2;
	if(p<c)
		return tree[k]+getval(p,a,c,k*2+1);
	else
		return tree[k]+getval(p,c,b,k*2+2);
}

int go[1000100][26];
int par[1100000];
char pch[1100000];
int link[1100000];
vector<int> unlink[1100000];
int idx[1100000];
int end[1100000];
int vert[110000];
int cnt=1;
int n;
char line[1100000];
bool incl[110000];
int tim;

int addword(const char *s){
	int v=0;
	for(int i=0;s[i];++i){
		if(go[v][s[i]-'a']==-1){
			par[cnt]=v;
			pch[cnt]=s[i]-'a';
			go[v][s[i]-'a']=cnt++;
		}
		v=go[v][s[i]-'a'];
	}
	return v;
}

int getgo(int v,char c);
 
int getlink(int v){
	if(link[v]==-1){
		if(!v||!par[v])
			link[v]=0;
		else
			link[v]=getgo(getlink(par[v]),pch[v]);
		if(v)
			unlink[link[v]].pb(v);
	}
	return link[v];
}

int getgo(int v,char c){
	if(go[v][c]==-1)
		go[v][c]=v==0?0:getgo(getlink(v),c);
	return go[v][c];
}

void undfs(int v){
	idx[v]=tim++;
	forv(i,unlink[v]){
		int p=unlink[v][i];
		undfs(p);
	}
	end[v]=tim;
}

lng solve(const char *s){
	lng res=0;
	int v=0;
	for(int i=0;s[i];++i){
		v=go[v][s[i]-'a'];
		res+=getval(idx[v],0,cnt,0);
	}
	return res;
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	memset(go,-1,sizeof(go));
	memset(par,-1,sizeof(par));
	memset(link,-1,sizeof(link));

	int m,n;
	cin>>m>>n;
	gets(line);
	forn(i,n){
		gets(line);
		vert[i]=addword(line);
		incl[i]=true;
	}

	forn(i,cnt){
		getlink(i);
		forn(j,26){
			getgo(i,j);
		}
	}

	tim=0;
	undfs(0);

	build(0,cnt,0);

	forn(i,n){
		addseg(1,idx[vert[i]],end[vert[i]],0,cnt,0);
	}

	forn(q,m){
		gets(line);
		if(line[0]=='-'||line[0]=='+'){
			int v=line[0]=='-'?-1:1;
			int a;
			sscanf(line+1,"%d",&a);
			--a;
			if((v==1)!=incl[a]){
				incl[a]=v==1;
				addseg(v,idx[vert[a]],end[vert[a]],0,cnt,0);
			}
		}else if(line[0]=='?'){
			printf("%I64d\n",solve(line+1));
		}else exit(123);
	}

    return 0;
}