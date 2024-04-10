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



int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);

	int n,k;
	cin>>n>>k;
	vector<pair<lng,int> > ts,ks;
	lng sum=0;
	forn(i,n){
		lng c;
		int t;
		cin>>c>>t;
		sum+=c*2LL;
		if(t==1)
			ts.pb(mp(c,i));
		else
			ks.pb(mp(c,i));
	}
	sort(all(ts));
	vector<vector<pair<lng,int> > > res(k);
	vector<bool> nice(k,false);
	int p=0;
	while(p<k-1&&ts.size()){
		nice[p]=true;
		res[p++].pb(ts.back());
		ts.pop_back();
	}
	while(p<k-1&&ks.size()){
		res[p++].pb(ks.back());
		ks.pop_back();
	}
	if(p!=k-1)
		exit(321);
	if(ts.size())
		nice[k-1]=true;
	res[k-1].insert(res[k-1].end(),all(ts));
	res[k-1].insert(res[k-1].end(),all(ks));
	forn(i,k){
		sort(all(res[i]));
		if(nice[i])
			sum-=res[i][0].X;
	}
	printf("%.1lf\n",sum/2.);
	forn(i,k){
		cout<<res[i].size();
		forv(j,res[i]){
			cout<<' '<<res[i][j].Y+1;
		}
		cout<<'\n';
	}

    return 0;
}