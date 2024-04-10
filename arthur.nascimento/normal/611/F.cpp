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
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 500500

using namespace std;

char str[maxn];

main(){

	int k,n,m;
	scanf("%d%d%d",&k,&n,&m);

	for(int i=0;i<k;i++)
		scanf(" %c",str+i);


	int x1 = 0, x2 = n-1, y1 = 0, y2 = m-1;
	int xm = 0, xM = 0, ym = 0 , yM = 0;
	int x1b, x2b, y1b, y2b;
	int dx1, dx2, dy1, dy2;
	int dx = 0, dy = 0;

	long long s = 0;
	long long A, B, C, D, E, F, G;
	long long at;
	long long rz;
	
	for(int i=1;i<=4*k;i++){
		int u = (i-1)%k;
		if(str[u] == 'U')
			dx++;
		if(str[u] == 'D')
			dx--;
		if(str[u] == 'L')
			dy--;
		if(str[u] == 'R')
			dy++;
		if(dx > xM){
			xM = dx;
			if(x2 < x1) goto p;
			x2--;
			int r = max(0,y2-y1+1);
			s += (long long)i * r;
			s %= mod;
		}
		if(dx < xm){
			xm = dx;
			if(x1 > x2) goto p;
			x1++;
			int r = max(0,y2-y1+1);
			s += (long long)i * r;
			s %= mod;
		}
		if(dy > yM){
			yM = dy;
			if(y2 < y1) goto p;
			y2--;
			int r = max(0,x2-x1+1);
			debug("+ %d * %d\n",i,r);
			s += (long long)i * r;
			s %= mod;
		}
		if(dy < ym){
			ym = dy;
			if(y1 > y2) goto p;
			y1++;
			int r = max(0,x2-x1+1);
			s += (long long)i * r;
			s %= mod;
		}
		p:
		if(i == k)
			A = s;
		if(i == 2*k)
			B = s, x1b = x1, x2b = x2, y1b = y1, y2b = y2;
		if(i == 3*k)
			C = s, dx1 = x1-x1b, dy1 = y1-y1b, dx2 = x2-x2b, dy2 = y2-y2b;
		if(i == 4*k){
			D = s;
			D = (D-C+mod)%mod;
			C = (C-B+mod)%mod;
			B = (B-A+mod)%mod;
			F = (D-C+mod)%mod;
			E = (C-B+mod)%mod;
			G = (F-E+mod)%mod;
			at = s;
		}
		if(i%k == 0){
			debug("%d\n",i);
			debug("s %lld x %d-%d y %d-%d\n",s,x1,x2,y1,y2);
			if(i > 4*k){
				F += G;
				D += F;
				at = (at+D)%mod;
				debug("era %lld\n",at);
			}
		}
	}

	debug("s %lld x %d-%d y %d-%d\n",s,x1,x2,y1,y2);
	debug("dx %d %d dy %d %d\n",dx1,dx2,dy1,dy2);
	debug("ABC %lld %lld %lld\n",A,B,C);
	int ux = dx/4;
	int uy = dy/4;

	//C -= B;
	//B -= A;
	//long long rz = (C-B+mod)%mod;
	int t = 4;

	if(ux == 0 && uy == 0){
		if(x1 > x2 || y1 > y2)
			printf("%lld\n",s);
		else
			printf("-1\n");
		return 0;
	}
	if(k == 100000)
		debug("%d %d %d %d %d %d %lld\n",ux,uy,x1,x2,y1,y2,s);

	if(x2 >= x1 && y2 >= y1)
	while(x2+dx2 >= x1+dx1 && y2+dy2 >= y1+dy1){
		t++;
		F = (F+G)%mod;
		D = (D+F)%mod;
		s = (s+D)%mod;
		x2 += dx2;
		y2 += dy2;
		x1 += dx1;
		y1 += dy1;
		//debug("s %lld x %d-%d y %d-%d\n",s,x1,x2,y1,y2);
	}
	debug("-- s %lld x %d-%d y %d-%d\n",s,x1,x2,y1,y2);

	for(long long i=(long long)k*t+1;i<=(long long)(k)*(t+2);i++){
		int u = (i-1)%k;
		if(str[u] == 'U')
			dx++;
		if(str[u] == 'D')
			dx--;
		if(str[u] == 'L')
			dy--;
		if(str[u] == 'R')
			dy++;
		if(dx > xM){
			xM = dx;
			if(x2 < x1) continue;
			x2--;
			int r = max(0,y2-y1+1);
			s += (long long)i * r;
			s %= mod;
		}
		if(dx < xm){
			xm = dx;
			if(x1 > x2) continue;
			x1++;
			int r = max(0,y2-y1+1);
			s += (long long)i * r;
			s %= mod;
		}
		if(dy > yM){
			yM = dy;
			if(y2 < y1) continue;
			y2--;
			int r = max(0,x2-x1+1);
			s += (long long)i * r;
			s %= mod;
		}
		if(dy < ym){
			ym = dy;
			if(y1 > y2) continue;
			y1++;
			int r = max(0,x2-x1+1);
			s += (long long)i * r;
			s %= mod;
		}
	}
	assert(x1 > x2 || y1 > y2);

	printf("%lld\n",s);

}