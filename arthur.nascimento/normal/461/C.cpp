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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 300300

using namespace std;

int T[maxn];

int query(int idx){
	idx++;
	int ret = 0;
	while(idx){
		ret += T[idx];
		idx -= idx&-idx;
	}
	return ret;
}

void update(int idx,int val){
	idx++;
	while(idx < maxn){
		T[idx] += val;
		idx += idx&-idx;
	}
}

main(){

		int n,q;
		scanf("%d%d",&n,&q);

		int p0 = 0;
		int pf = n-1;
		int inv = 0;

		for(int i=0;i<n;i++)
			update(i,1);

		while(q--){

			int t;
			scanf("%d",&t);

			if(t == 1){
				int u;
				scanf("%d",&u);
				debug("u = %d\n",u);
				yy:
				
				
				if(u <= (pf-p0+1)/2){

					if(inv){

						for(int i=0;i<u;i++){
							debug("i=%d u=%d\n",i,u);
							int len = query(pf-i) - query(pf-i-1);
							update(pf-2*u+i+1,len);
							debug("v[%d] += v[%d] (%d)\n",pf-2*u+i+1,pf-i,len);
						}
						pf -= u;
							

						continue;
					}					
				
					for(int i=0;i<u;i++){
						int len = query(p0+i) - query(p0+i-1);
						debug("len = %d\n",len);
						update(p0+2*u-i-1,len);
						debug("v[%d] += %d\n",p0+2*u-i-1,len);
					}
					p0 += u;
					debug("p0 = %d\n",p0);

					
					continue;
				}

				debug("inv\n\n\n");
				inv ^= 1;
				u = (pf-p0) - u+1;
				goto yy;
				
			
			}

			else {
				int a,b;
				scanf("%d%d",&a,&b);
				if(inv){
					a = pf-p0-a+1;
					b = pf-p0-b+1;
					swap(a,b);
				}
				b--;
				debug("p0 = %d\n",p0);
				int res = query(p0+b);
				if(p0+a) res -= query(p0+a-1);
				printf("%d\n",res);
			}

		}

}