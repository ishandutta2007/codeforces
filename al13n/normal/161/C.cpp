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

struct nyan{
	vector<PII> maxl[30];
	set<PII> was;

	void doit(int a,int b){
		if(was.count(mp(a,b)))
			return;
		was.insert(mp(a,b));
		if(b<a)
			return;
		int n=29;
		int p=1<<29;
		while(true){
			while(a>p){
				a-=p;
				b-=p;
			}
			if(b>=p)
				break;
			--n;
			p>>=1;
		}
		maxl[n].pb(mp(p-a,b-p));
		doit(a,p-1);
		doit(p+1,b);
	}

	void norm(){
		forn(n,30){
			vector<PII> t=maxl[n];
			sort(all(t));
			reverse(all(t));
			maxl[n].clear();
			int my=-iinf;
			forv(i,t){
				if(t[i].Y>my){
					my=t[i].Y;
					maxl[n].pb(t[i]);
				}
			}
		}
	}
};

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

	int a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	nyan n1,n2;
	n1.doit(a1,b1);
	n2.doit(a2,b2);
	n1.norm();
	n2.norm();

	int res=0;
	forn(n,30){
		forv(i,n1.maxl[n]){
			forv(j,n2.maxl[n]){
				PII a=n1.maxl[n][i];
				PII b=n2.maxl[n][j];
				res=max(res,1+min(a.X,b.X)+min(a.Y,b.Y));
			}
		}
	}
	cout<<res;

    return 0;
}