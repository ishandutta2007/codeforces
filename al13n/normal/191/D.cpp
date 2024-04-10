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
#include <ctime>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define linf 1000000000000000000LL
#define dinf 1e200
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-5
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define PII pair<int,int> 
#define PLL pair<lng,lng> 
#define PDD pair<double,double> 
#define X first
#define Y second
#define unlink asdunlink
typedef unsigned char uchar;
typedef unsigned int uint;
inline int mymax(int a,int b){return a<b?b:a;}
inline int mymin(int a,int b){return a>b?b:a;}
inline lng mymax(lng a,lng b){return a<b?b:a;}
inline lng mymin(lng a,lng b){return a>b?b:a;}

vector<int> gr[110000];
int n;
bool was[110000];
int res=0;

PII dfs(int v,int pr){
	was[v]=true;
	int r=-1;
	int rr=-1;
	int c=0;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		if(was[p])
			if(rr!=-1)
				exit(4);
			else
				rr=p;
		else{
			PII t=dfs(p,v);
			if(t.X!=-1){
				if(r!=-1)
					exit(123);
				r=t.X;
				c+=t.Y;
			}
		}
	}
	if(gr[v].size()>=3)
		++c;
	res+=gr[v].size()%2;
	if(r==v){
		if(c<2)
			res+=2;
		return mp(-1,-1);
	}else if(rr!=-1){
		if(r!=-1)
			exit(2);
		return mp(rr,c);
	}else if(r!=-1){
		return mp(r,c);
	}else{
		return mp(-1,-1);
	}
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	int m;
	cin>>n>>m;
	forn(i,m){
		int a,b;
		cin>>a>>b;
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	dfs(0,-1);
	if(res%2)
		exit(6);
	cout<<res/2<<' '<<m;

    return 0;
}