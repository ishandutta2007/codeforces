#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) //fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 200200

typedef long long ll;
using namespace std;

ll sum = 0;

struct bla {
	int p,t,rel;
	bool operator<(bla comp)const{
		return (ll) p * comp.t > (ll) t * comp.p;
	}
	inline bool operator==(bla comp){
		return !(*this<comp) && !(comp<*this);
	}
	inline double eval(double c,ll x){
		return (double) p * (1.0 - c * (double) x / sum);
	}
};

bla v[maxn];

double T[2][4*maxn];

inline double query(int init,int fim,int p,int l,int r,int t){
	if(l > r || l > fim || r < init)
		return t ? -1 : 1e9;
	if(init >= l && fim <= r)
		return T[t][p];
	double a1,a2;
	int mid = (init+fim)/2;
	a1 = query(init,mid,2*p,l,r,t);
	a2 = query(mid+1,fim,2*p+1,l,r,t);
	if(t == 0)
		return min(a1,a2);
	else
		return max(a1,a2);
}

inline void update(int init,int fim,int p,int pos,double val,int t){
	if(init > pos || fim < pos)
		return;
	if(init == fim){
		if(t == 0)
			T[0][p] = min(T[0][p],val);
		else
			T[1][p] = max(T[1][p],val);
		return;
	}
	int mid = (init+fim)/2;
	update(init,mid,2*p,pos,val,t);
	update(mid+1,fim,2*p+1,pos,val,t);
	T[0][p] = min(T[0][2*p],T[0][2*p+1]);
	T[1][p] = max(T[1][2*p],T[1][2*p+1]);
}

inline void clear(int init,int fim,int p){
	T[0][p] = 1e9;
	T[1][p] = -1;
	if(init != fim){
		int mid = (init+fim)/2;
		clear(init,mid,2*p);
		clear(mid+1,fim,2*p+1);
	}
} 	

int ret;
char ch;
inline int read(){
	ret = 0;
	while((ch=getchar()) >= '0')
		ret = 10*ret+ch-'0';
	return ret;
}

main(){

	int n = read();

	vector<int> cx;
	map<int,int> mp;

	for(int i=0;i<n;i++){
		v[i].p = read();
		cx.pb(v[i].p);
	}

	for(int i=0;i<n;i++){
		v[i].t = read();
		sum += v[i].t;
	}

	sort(cx.begin(), cx.end());

	mp[cx[0]] = 0;
	for(int i=1;i<n;i++){
		mp[cx[i]] = mp[cx[i-1]];
		if(cx[i-1] != cx[i])
			mp[cx[i]]++;
	}

	for(int i=0;i<n;i++)
		v[i].rel = mp[v[i].p];

	sort(v,v+n);

	double low = 0, up = 1;

	for(int k=0;k<25;k++){

		double mid = (low+up)/2;
		debug("mid %.8lf\n",mid);

		clear(0,n-1,1);

		int p = 0;
		ll tot = 0;

		int ok = 1;

		while(p < n){

			debug("p %d\n",p);
			int p0 = p;
			ll T = 0;
			while(p+1 < n && v[p] == v[p+1]){
				T += v[p].t;
				p++;
			}
			T += v[p].t;
			debug("T %d\n",(int)T);

			for(int i=p0;i<=p;i++){
				debug("i %d p %d t %d rel %d\n",i,v[i].p,v[i].t,v[i].rel);
				double men = v[i].eval(mid,tot+T);
				double mai = v[i].eval(mid,tot+v[i].t);
				debug("min %.8lf max %.8lf\n",men,mai);
				update(0,n-1,1,v[i].rel,men,0);
				update(0,n-1,1,v[i].rel,mai,1);
				if(query(0,n-1,1,0,v[i].rel-1,1) > men || query(0,n-1,1,v[i].rel+1,n-1,0) < mai)
					ok = 0;
			}

			tot += T;
			p++;
		
		}

		if(ok)
			low = mid;
		else
			up = mid;

	}

	printf("%.8lf\n",low);

}