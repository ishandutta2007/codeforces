#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n,a[2][1024][1024],F[2][1024][1024];
int zx=-1,zy;

int f(int k,int x,int y){
	if(x>=n || y>=n) return -1u/4;
	int &res=F[k][x][y];
	if (res<0) 
		if (x+1==n && y+1==n) res = a[k][x][y];
		else 
			res = a[k][x][y] + min(f(k,x+1,y), f(k,x,y+1));
	return res;
}

void restore(int k,int x,int y){
	if(x+1==n && y+1==n) return;
	if(f(k,x,y)==a[k][x][y]+f(k,x+1,y))
		putchar('D'),restore(k,x+1,y);
	else putchar('R'),restore(k,x,y+1);
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin>>n;
	REP(i,n)REP(j,n){
		int v; scanf("%d",&v);
		if(v) {
			for(;v%2==0;v/=2) ++a[0][i][j];
			for(;v%5==0;v/=5) ++a[1][i][j];
		}else{
			zx = i, zy = j;
			a[0][i][j]=a[1][i][j]=1<<20;
		}
	}
	CL(F,-1);
	int res=min(f(0,0,0),f(1,0,0));
	if((~zx) && 1<=res) {
		puts("1");
		cout<<string(zx,'D')<<string(n-1,'R')<<string(n-1-zx,'D')<<endl;
	} else {
		cout<<res<<endl;
		restore((f(1,0,0)==res),0,0);
		puts("");
	}
	return 0;
}