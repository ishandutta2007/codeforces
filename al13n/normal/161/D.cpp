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
typedef unsigned char uchar;

vector<int> gr[51000];
int C[51000][510];
int n,k;
lng res;

void dfs(int v,int pr){
	C[v][0]=1;
	forv(i,gr[v]){
		int p=gr[v][i];
		if(p==pr)
			continue;
		dfs(p,v);
		forn(j,k){
			res+=1LL*C[p][j]*C[v][k-j-1];
		}
		forn(j,k){
			C[v][j+1]+=C[p][j];
		}
	}
}

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);

	cin>>n>>k;
	forn(i,n-1){
		int a,b;
		scanf("%d%d",&a,&b);
		--a;--b;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	dfs(0,-1);
	cout<<res;

    return 0;
}