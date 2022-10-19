#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back

using namespace std;

int v[100100];

long long T[4*100100];

void update(int init,int fim,int p,int pos,int val){

	if(init > pos || fim < pos)
		return;

	if(init == fim){
		T[p] = val;
		return;
	}

	int mid = (init+fim)/2;

	if(pos <= mid)
		update(init,mid,2*p,pos,val);
	else
		update(mid+1,fim,2*p+1,pos,val);

	T[p] = T[2*p] + T[2*p+1];

}


long long query(int init,int fim,int p,int qx,int qy){

	if(init > qy || fim < qx)
		return 0;

	if(init >= qx && fim <= qy)
		return T[p];

	int mid = (init+fim)/2;

	return query(init,mid,2*p,qx,qy) + query(mid+1,fim,2*p+1,qx,qy);

}

int T2[4*100100];

void update2(int init,int fim,int p,int pos,int val){

	if(init > pos || fim < pos)
		return;

	if(init == fim){
		T2[p] = val;
		return;
	}

	int mid = (init+fim)/2;
	update2(init,mid,2*p,pos,val);
	update2(mid+1,fim,2*p+1,pos,val);
	T2[p] = max(T2[2*p],T2[2*p+1]);
	
}

int _next;

int query2(int init,int fim,int p,int qx,int qy,int mod){

	if(init > qy || fim < qx)
		return 0;

	if(_next < init)
		return 0;

	if(T2[p] < mod)
		return 0;

	debug("query2 %d~%d qx = %d qy = %d\n",init,fim,qx,qy);

	if(init >= qx && fim <= qy)
		_next = min(_next,fim);

	if(init == fim)
		return 0;

	int mid = (init+fim)/2;
	return max(query2(mid+1,fim,2*p+1,qx,qy,mod),query2(init,mid,2*p,qx,qy,mod));

}

char ch;
int read(){
	int x=0;
	while((ch=getchar()) < '0');
	x = ch-'0';
	while((ch=getchar()) >= '0')x = 10*x+ch-'0';
	return x;
}

main(){

		int n,m;
		//scanf("%d%d",&n,&m);
		n = read();
		m = read();

		for(int i=0;i<n;i++){
			v[i] = read();
			update(0,n-1,1,i,v[i]);
			update2(0,n-1,1,i,v[i]);
		}			

		for(int i=0;i<m;i++){

			int t;
			scanf("%d",&t);

			if(t == 1){
				int l,r;
				l = read();
				r = read();
				l--, r--;
				printf("%I64d\n",query(0,n-1,1,l,r));
			}

			if(t == 3){
				int k,x;
				k = read();
				x = read();
				k--;
				v[k] = x;
				update(0,n-1,1,k,x);
				debug("update v[%d] := %d\n",k,x);

				update2(0,n-1,1,k,x);
				
			}

			if(t == 2){

				int l,r,mod;
				l = read();
				r = read();
				mod = read();

				l--, r--;

				int p = l;

				//debug("max %d~%d = %d\n",p,r,query2(0,n-1,1,p,r));
				while(p <= r){

					int low=p, up=r;

					/*while(low-up){
						int mid = (low+up)/2;
						if(query2(0,n-1,1,p,mid) >= mod)
							up = mid;
						else
							low = mid+1;
					}*/

					_next = n;
					query2(0,n-1,1,p,r,mod);
					low = _next;

					if(low == n)
						break;

					debug("low = %d v[low] = %d\n",low,v[low]);
					assert(v[low] >= mod);
					v[low] %= mod;
					update(0,n-1,1,low,v[low]);
					update2(0,n-1,1,low,v[low]);
					debug("update v[%d] := %d\n",low,v[low]);

					p = low+1;
						
				}

				

			}

		}

}