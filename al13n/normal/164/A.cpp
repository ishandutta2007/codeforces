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

int col[110000];
vector<int> gr[110000];
vector<int> igr[110000];
bool was1[110000];
bool was2[110000];
int n,m;

void dfs1(int v){
	if(was1[v])
		return;
	was1[v]=true;
	forv(i,gr[v]){
		int p=gr[v][i];
		dfs1(p);
	}
}

void dfs2(int v){
	if(was2[v])
		return;
	was2[v]=true;
	if(col[v]!=1){
		forv(i,igr[v]){
			int p=igr[v][i];
			dfs2(p);
		}
	}
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	cin>>n>>m;
	forn(i,n){
		scanf("%d",col+i);
	}
	forn(i,m){
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		gr[a].pb(b);
		igr[b].pb(a);
	}

	forn(i,n){
		if(col[i]==1)
			dfs1(i);
		if(col[i]==2)
			dfs2(i);
	}

	forn(i,n){
		printf("%d\n",((was1[i]&&was2[i]) ? 1 : 0));
	}
	
    return 0;
}