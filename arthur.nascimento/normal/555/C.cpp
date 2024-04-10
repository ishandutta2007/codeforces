#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 999999999
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 200200

using namespace std;

vector<int> vx;
vector<int> vy;

int T[2][4*maxn];
int lazy[2][4*maxn];

int qx[maxn];
int qy[maxn];
char qt[maxn];

void refresh(int init,int fim,int p,int id){
	if(init == fim)
		T[id][p] = max(T[id][p],lazy[id][p]);
	else {
		lazy[id][2*p] = max(lazy[id][2*p],lazy[id][p]);
		lazy[id][2*p+1] = max(lazy[id][2*p+1],lazy[id][p]);
	}
}

void update(int init,int fim,int p,int l,int r,int val,int id){
	refresh(init,fim,p,id);
	if(init > r || fim < l) return;
	if(init >= l && fim <= r){
		lazy[id][p] = max(lazy[id][p],val);
		refresh(init,fim,p,id);
		return;
	}
	int mid = (init+fim)/2;
	update(init,mid,2*p,l,r,val,id);
	update(mid+1,fim,2*p+1,l,r,val,id);
}

int query(int init,int fim,int p,int pos,int id){
	refresh(init,fim,p,id);
	if(init > pos || fim < pos)
		return 0;
	if(init == fim)
		return T[id][p];
	int mid = (init+fim)/2;
	return query(init,mid,2*p,pos,id) + query(mid+1,fim,2*p+1,pos,id);
}

pii getx(int a,int b){
	if(a > b) return pii(-1,-1);
	vector<int> :: iterator A = lower_bound(vx.begin(),vx.end(),a);
	vector<int> :: iterator B = upper_bound(vx.begin(),vx.end(),b);
	if(B == vx.begin() || A > --B || A == vx.end())
		return pii(-1,-1);
	return pii(A-vx.begin(),B-vx.begin());
}

pii gety(int a,int b){
	if(a > b) return pii(-1,-1);
	vector<int> :: iterator A = lower_bound(vy.begin(),vy.end(),a);
	vector<int> :: iterator B = upper_bound(vy.begin(),vy.end(),b);
	if(B == vy.begin() || A > --B || A == vy.end())
		return pii(-1,-1);
	return pii(A-vy.begin(),B-vy.begin());
}

main(){

	int n,q;
	scanf("%d%d",&n,&q);

	for(int i=0;i<q;i++){
		scanf("%d%d %c",qx+i,qy+i,qt+i);
		if(qt[i] == 'U')
			vx.pb(qx[i]);
		else
			vy.pb(qy[i]);
	}

	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());

	map<int,int> mpx, mpy;

	int cur = 1;
	if(vx.size()) mpx[vx[0]] = 0;
	for(int i=1;i<vx.size();i++)
		if(vx[i] != vx[i-1])
			mpx[vx[i]] = cur++;
			
	cur = 1;
	if(vy.size()) mpy[vy[0]] = 0;
	for(int i=1;i<vy.size();i++)
		if(vy[i] != vy[i-1])
			mpy[vy[i]] = cur++;

	vx.resize(distance(vx.begin(),unique(vx.begin(),vx.end())));
	vy.resize(distance(vy.begin(),unique(vy.begin(),vy.end())));

	for(int i=0;i<q;i++){
		debug("i=%d\n",i);
		if(qt[i] == 'U'){
			int h = query(0,q-1,1,mpx[qx[i]],0);
			printf("%d\n",qy[i]-h);
			pii range = gety(h+1,qy[i]);
			debug("(%d;%d) -> (%d;%d)\n",h+1,qy[i],range.first,range.second);
			if(range.first+1)
				update(0,q-1,1,range.first,range.second,qx[i],1);
			update(0,q-1,1,mpx[qx[i]],mpx[qx[i]],qy[i],0);
		}
		else {
			int h = query(0,q-1,1,mpy[qy[i]],1);
			printf("%d\n",qx[i]-h,h);
			pii range = getx(h+1,qx[i]);
			debug("(%d;%d) -> (%d;%d)\n",h+1,qx[i],range.first,range.second);
			if(range.first+1)
				update(0,q-1,1,range.first,range.second,qy[i],0);
			update(0,q-1,1,mpy[qy[i]],mpy[qy[i]],qx[i],1);
		}
	}

}