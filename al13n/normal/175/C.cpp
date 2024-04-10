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
#define eps 1e-11
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
#define mset(a,b) memset(a,b,sizeof(a))
typedef unsigned short ushort;

int n;
PII figs[110];
int m;
lng cnts[110];

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(false);

	cin>>n;
	forn(i,n){
		cin>>figs[i].Y>>figs[i].X;
	}
	sort(figs,figs+n);
	cin>>m;
	forn(i,m){
		cin>>cnts[i];
	}
	cnts[m]=linf;
	lng cur=0;
	int p=0;
	lng res=0;
	forn(i,n){
		lng c=figs[i].Y;
		while(c){
			lng t=min(cnts[p]-cur,c);
			res+=(p+1)*t*figs[i].X;
			cur+=t;
			c-=t;
			if(cur==cnts[p])
				++p;
		}
	}
	cout<<res;

	return 0;
}