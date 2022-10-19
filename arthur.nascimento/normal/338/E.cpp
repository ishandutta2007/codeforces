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

#define inf (999999999999LL)
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
#define maxn 150150

using namespace std;

int T[4*maxn];
int lazy[4*maxn];

void refresh(int init,int fim,int p){
	T[p] += lazy[p];
	if(fim-init){
		lazy[2*p] += lazy[p];
		lazy[2*p+1] += lazy[p];
	}
	lazy[p] = 0;
}

void update(int init,int fim,int p,int l,int r,int k){

	refresh(init,fim,p);

	if(init > r || fim < l) return;

	if(init >= l && fim <= r){
		debug("%d..%d += %d\n",init,fim,k);
		lazy[p] += k;
		refresh(init,fim,p);
		debug("max[%d..%d] = %d\n",init,fim,T[p]);
		return;
	}

	int mid = (init+fim)/2;
	update(init,mid,2*p,l,r,k);
	update(mid+1,fim,2*p+1,l,r,k);
	T[p] = max(T[2*p], T[2*p+1]);
	debug("max[%d..%d] = %d\n",init,fim,T[p]);
	
}

int pos[maxn];

main(){

		map<int,int> last;

		int n,m,k;
		scanf("%d%d%d",&m,&n,&k);

		vector<pii> v;
		vector<int> u;
		vector<int> t;

		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			u.pb(a);
		}

		for(int i=0;i<m;i++){
			int a;
			scanf("%d",&a);
			v.pb(pii(a,i));
			t.pb(a);
		}


		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		sort(u.begin(), u.end());

		int p = 0;

		for(int i=0;i<n;i++){
			while(p+1 < v.size() && v[p+1].first + u[i] >= k) p++;
			if(v[p].first + u[i] < k){
				printf("0\n");
				return 0;
			}
			//while(p+1 < v.size() && v[p].first == v[p+1].first) p++;
			debug("mrk v[%d]\n",p);
			update(0,v.size()-1,1,p,p,i+1-last[p]);
			last[p] = i+1;
		}

		for(int i=0;i<m;i++)
			pos[v[i].second] = i;

		int ans = 0;

		debug("max = %d\n",T[1]);

		for(int i=0;i<n;i++){
			update(0,m-1,1,pos[i],m-1,-1); debug("add %d\n",pos[i]); }
		refresh(0,m-1,1);
		debug("max = %d\n",T[1]);
		if(T[1] <= 0) ans++;
			
		int l = 0;
		int r = n;
		
		while(r < m){
			update(0,m-1,1,pos[l],m-1,1); debug("tira %d\n",pos[l]);
			update(0,m-1,1,pos[r],m-1,-1); debug("add %d\n",pos[r]);
			l++, r++;
			refresh(0,m-1,1);
			debug("max = %d\n",T[1]);
			if(T[1] <= 0) ans++;
		}

		printf("%d\n",ans);

}