#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
using namespace std;
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,(int)(v).size())
#define iinf 1000000000
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define lng long long
#define eps 1e-8
#define SQ(a) ((a)*(a))
#define PI 3.14159265359
#define index asdindex
#define FI first
#define SE second

int n,m;
int A[110000];
int H[110000];
int L[110000];
int R[110000];
pair<int,int> mush[110000];
pair<double,int> add[110000];

int main(){
#ifdef __ASD__
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif

	ios_base::sync_with_stdio(false);

	cin>>n>>m;
	forn(i,n)
		cin>>A[i]>>H[i]>>L[i]>>R[i];
	forn(i,m)
		cin>>mush[i].FI>>mush[i].SE;
	sort(mush,mush+m);
	forn(i,n){
		pair<double,int> v(0.,0);
		if(L[i]==100)
			v.SE=1;
		else
			v.FI=log(1-1.*L[i]/100);
		int p=lower_bound(mush,mush+m,mp(A[i]-H[i],-iinf))-mush;
		add[p].FI+=v.FI;
		add[p].SE+=v.SE;
		p=lower_bound(mush,mush+m,mp(A[i],-iinf))-mush;
		add[p].FI-=v.FI;
		add[p].SE-=v.SE;
		v=mp(0.,0);
		if(R[i]==100)
			v.SE=1;
		else
			v.FI=log(1-1.*R[i]/100);
		p=lower_bound(mush,mush+m,mp(A[i],+iinf))-mush;
		add[p].FI+=v.FI;
		add[p].SE+=v.SE;
		p=lower_bound(mush,mush+m,mp(A[i]+H[i],+iinf))-mush;
		add[p].FI-=v.FI;
		add[p].SE-=v.SE;
	}

	double res=0;

	double l=0;
	int z=0;
	forn(i,m){
		l+=add[i].FI;
		z+=add[i].SE;
		if(z<0)
			exit(3234);
		if(z==0)
			res+=mush[i].SE*exp(l);
	}
	printf("%.15lf",res);

	return 0;
}