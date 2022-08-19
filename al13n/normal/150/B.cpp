#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
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
#define eps 1e-10
#define EQ(a,b) (fabs((a)-(b))<eps)
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second
#define prev asdprev
#define ends asdends
#define PII pair<int,int>
#define X first
#define Y second

vector<int> gr[2100];
int n,m,k;
bool was[2100];

void dfs(int v){
	if(was[v])
		return;
	was[v]=true;
	forv(i,gr[v]){
		int p=gr[v][i];
		dfs(p);
	}
}

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);

	cin>>n>>m>>k;
	forn(i,n-k+1){
		forn(j,k){
			gr[i+j].pb(i+k-j-1);
		}
	}
	int c=0;
	forn(i,n){
		if(!was[i]){
			++c;
			dfs(i);
		}
	}
	
	const lng mod=iinf+7;
	lng r=1;
	lng a=m;
	while(c){
		if(c%2){
			--c;
			r=r*a%mod;
		}else{
			c/=2;
			a=a*a%mod;
		}
	}
	
	cout<<r;

	return 0;
}