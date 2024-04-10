/*
 * test.cpp
 *
 *
 *      Author: Fireworks
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<bitset>
#include<set>
#include<iomanip>
#include<fstream>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<list>
#include<sstream>
#include<cassert>   // assert

using namespace std;

//#define double long double

typedef pair<int,int> ii;
typedef pair<int,long long> il;
typedef pair<long long,long long> ll;
typedef pair<ll,int> lli;
typedef pair<long long,int> li;
typedef pair<double,double> dd;
typedef pair<ii,int> iii;
typedef pair<double,int> di;
long long mod = 1000000007LL;
long long base = 10000007;
long long large = 1000000000000000000LL;



vector<vector<long long> > addv;

int ul,ur;
long long uv1,uv2;
void update(int o,int l,int r){
	if(ul<=l&&ur>=r){
		addv[o][0]+=uv1;
		addv[o][1]+=uv2;
	}else{
		int m = (l+r)/2;
		if(ul<=m) update(o*2,l,m);
		if(ur>m) update(o*2+1,m+1,r);
	}
}

int qp,re;
void query(int o,int l,int r,long long add1,long long add2){
	add1+=addv[o][0];
	add2+=addv[o][1];
	if(l==r){
		re=add1*l+add2;
	}else{
		int m = (l+r)/2;
		if(qp<=m) query(o*2,l,m,add1,add2);
		if(qp>m) query(o*2+1,m+1,r,add1,add2);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> s(n,0),g(n,0);
	for(int i=0;i<n;i++) {
		scanf("%d%d",&s[i],&g[i]);
		s[i]+=i;
	}

	//addv.assign(4*sz+10,vector<long long>(2,0));


	int ub = s[0]+g[0];
	int lb = s[0];

	/*ul = lb;
	ur = ub;
	uv1 = 1;
	uv2 = -s[0];
	update(1,0,sz-1);*/
	for(int i=1;i<n;i++){
		/*qp = ub;
		query(1,0,sz-1,0,0);
		long long temp = re;
		qp = ub+1;
		query(1,0,sz-1,0,0);
		ul=ur=ub+1;
		uv1=0;
		uv2 = temp-re;
		update(1,0,sz-1);
		qp = ub+2;
		query(1,0,sz-1,0,0);
		ul=ur=ub+2;
		uv1=0;
		uv2 = temp-re;
		update(1,0,sz-1);*/

		ub+=2;
		ub = min(ub,s[i]+g[i]);
		lb = max(lb,s[i]);
		if(lb>ub){
			cout<<-1<<endl;
			return 0;
		}
		g[i] = min(g[i],ub-s[i]);


		/*ul = lb;
		ur = ub;
		uv1 = 1;
		uv2 = -s[i];
		update(1,0,sz-1);*/

	}

	long long ans = 0;
	vector<int> e(n,0);
	for(int i=n-1;i>=0;i--){
		ub = min(ub,s[i]+g[i]);
		e[i] = ub-i;
		ans += 1LL*(ub-s[i]);
	}
	cout<<ans<<endl;
	for(int i=0;i<n;i++) cout<<e[i]<<" ";
	/*cout<<ub<<endl;
	qp = ub;
	query(1,0,sz-1,0,0);
	cout<<re<<endl;*/








	return 0;

}