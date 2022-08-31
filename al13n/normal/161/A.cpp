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

struct event{
	int a,b;
	int id;
	bool operator<(const event &e)const{
		return b<e.b;
	}
};

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

	int n,m,x,y;
	cin>>n>>m>>x>>y;
	vector<int> as(n),bs(m);
	forn(i,n){
		cin>>as[i];
	}
	forn(i,m){
		cin>>bs[i];
	}
	int a=0,b=0;
	vector<PII> res;
	while(a<n&&b<m){
		if(bs[b]<as[a]-x)
			++b;
		else if(bs[b]>as[a]+y)
			++a;
		else{
			res.pb(mp(a,b));
			++a;
			++b;
		}
	}
	cout<<res.size()<<endl;
	forv(i,res){
		cout<<res[i].X+1<<' '<<res[i].Y+1<<'\n';
	}

    return 0;
}