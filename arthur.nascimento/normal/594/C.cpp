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

struct ev {
	int x,y1,y2,tipo,sinal,idx;
	ev(int x=0,int y1=0,int y2=0,int tipo=0,int sinal=0,int idx=0): x(x), y1(y1), y2(y2), tipo(tipo), sinal(sinal), idx(idx) {}
	bool operator<(ev comp)const{			
		return x < comp.x;
	}
}

E[4*maxn];

int inv[8*maxn];
unsigned long long area[4*maxn];
int ans[maxn];

long long T[8*maxn];
void update(int idx){
	idx++;
	while(idx < 8*maxn){
		T[idx]++;
		idx += idx&-idx;
	}
}

long long query(int idx){
	long long ret = 0;
	idx++;
	while(idx){
		ret += T[idx];
		idx -= idx&-idx;
	}
	return ret;
}
     
main(){

	int n,k;
	scanf("%d%d",&n,&k);

	vector<int> vx, vy;
	vector<int> cord;

	int cnt = 0;

	for(int i=0;i<n;i++){
		int x,y;
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		x = a+c;
		y = b+d;
		debug("x %d y %d\n",x,y);
		E[cnt++] = ev(x,y,0,1,1);
		vx.pb(x);
		vy.pb(y);
		cord.pb(x);
		cord.pb(y);
	}

	sort(cord.begin(),cord.end());
	map<int,int> mp;
	mp[cord[0]] = 0;
	inv[0] = cord[0];
	debug("%d -> %d\n",cord[0],0);
	int u = 1;
	for(int i=1;i<cord.size();i++)
		if(cord[i] != cord[i-1]){
			inv[u] = cord[i];
			debug("%d -> %d\n",cord[i],u);
			mp[cord[i]] = u++;
		}


	for(int i=0;i<cnt;i++)
		E[i].x = mp[E[i].x], E[i].y1 = mp[E[i].y1];
	for(int i=0;i<vx.size();i++){
		vx[i] = mp[vx[i]];debug("x %d\n",vx[i]);}
	for(int i=0;i<vy.size();i++){
		vy[i] = mp[vy[i]]; debug("y %d\n",vy[i]);}
	

	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	vx.resize(distance(vx.begin(),unique(vx.begin(),vx.end())));
	vy.resize(distance(vy.begin(),unique(vy.begin(),vy.end())));

	int cur = 0;
	for(int x1=0;x1<vx.size() && x1 <= k;x1++)
		for(int x2=vx.size()-1;x2 >= 0 && x2 >= (int)vx.size()-k-1 && x2 >= x1; x2--)
			for(int y1=0;y1<vy.size() && y1 <= k;y1++)
				for(int y2=vy.size()-1;y2>=0 && y2 >= (int)vy.size()-k-1 && y2 >= y1; y2--){

					E[cnt++] = ev(vx[x1]-1,vy[y1],vy[y2],2,-1,cur);
					E[cnt++] = ev(vx[x2],vy[y1],vy[y2],2,1,cur);
					debug("era %d\n",vx[x1]);
					int X1 = inv[vx[x1]];
					int X2 = inv[vx[x2]];
					int Y1 = inv[vy[y1]];
					int Y2 = inv[vy[y2]];

					if(X2 == X1 || X2 == X1+1) X2++;
					if(Y2 == Y1 || Y2 == Y1+1) Y2++;
					area[cur] = (long long)((X2-X1+1)/2) * ((Y2-Y1+1)/2);
					debug("cur %d: X %d~%d Y %d~%d -> %I64d\n",cur,X1,X2,Y1,Y2,area[cur]);
					cur++;

				}

	stable_sort(E,E+cnt);

	for(int i=0;i<cnt;i++){

		if(E[i].tipo == 2){
			ans[E[i].idx] += (query(E[i].y2)-query(E[i].y1-1)) * E[i].sinal;
		}
		else 
			update(E[i].y1);

	}

	unsigned long long resp = 1000000000000000000LL;

	for(int i=0;i<cnt;i++)
		if(ans[i] >= n-k){
			resp = min(resp,area[i]);
			if(area[i] == 0)
			 	debug("!%d\n",i);
		}
	cout << resp << endl;

}