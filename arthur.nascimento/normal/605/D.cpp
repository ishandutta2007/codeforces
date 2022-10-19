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

int X1[maxn];
int X2[maxn];
int Y1[maxn];
int Y2[maxn];

set<pii> T[4*maxn];

void insert(int init,int fim,int p,int id){
		if(init > X1[id] || fim < X1[id])
			return;
		if(init == fim){
			T[p].insert(pii(Y1[id],id));
			return;
		}
		int mid = (init+fim)/2;
		insert(init,mid,2*p,id);
		insert(mid+1,fim,2*p+1,id);
		T[p].insert(pii(Y1[id],id));
}

int dcur = 0;
int at = 0;

queue<int> Q;

int dist[maxn];
int foi[maxn];
int prec[maxn];

void go(int init,int fim,int p,int X,int Y){
	if(init > X)
		return;
	if(fim <= X){
		
		while(T[p].size() > 0 && T[p].begin()->first <= Y){
			if(!foi[T[p].begin()->second]){
				Q.push(T[p].begin()->second),
				dist[T[p].begin()->second] = 1 + dcur,
				prec[T[p].begin()->second] = at;
			//	debug("%d -> %d\n",at,T[p].begin()->second);
			}
			foi[T[p].begin()->second] = 1;
			T[p].erase(T[p].begin());
		}
		
		return;	
	}
	int mid = (init+fim)/2;
	go(init,mid,2*p,X,Y);
	go(mid+1,fim,2*p+1,X,Y);
}

int bx1[maxn];
int by1[maxn];
int bx2[maxn];
int by2[maxn];

int dd[maxn];

int brute(int n){
	queue<int> A;
	for(int i=0;i<n;i++)
		if(bx1[i] == 0 && by1[i] == 0)
			A.push(i), dd[i] = 1;
	while(A.size()){
		int p = A.front();
		A.pop();
		debug("dd[%d] = %d\n",p,dd[p]);
		for(int i=0;i<n;i++){
				if(dd[i] == 0 && bx2[p] >= bx1[i] && by2[p] >= by1[i]){
					dd[i] = 1 + dd[p];
					A.push(i);
			}
			if(p == 0 && i == 4)
			 debug("!! %d %d %d %d\n", bx2[p] , bx1[i] , by2[p] , by1[i]);
		}
	
	}
	if(dd[n-1] == 0)
		return -1;
	return dd[n-1];
}

int ini[maxn];

int ret = 0;
char ch;
inline int r(){
	ret = 0;
	while((ch=getchar())>='0')
		ret = 10*ret+ch-'0';
		return ret;
}

main(){
		
		int n = r();
		//scanf("%d",&n);
		
		vector<pii> vx, vy;
		
		int has00 = 0;
		
		for(int i=1;i<=n;i++){
			int x1,y1,x2,y2;
			//scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x1 = r();
			y1 = r();
			x2 = r();
			y2 = r();
		//	bx1[i-1] = x1;
		//	by1[i-1] = y1;
		//	bx2[i-1] = x2;
		//	by2[i-1] = y2;
			if(x1 == 0 && y1 == 0)
				has00 = 1;
			vx.pb(pii(x1,i));
			vx.pb(pii(x2,-i));
			vy.pb(pii(y1,i));
			vy.pb(pii(y2,-i));
		}
		
		if(!has00){
				printf("-1\n");
				return 0;
		}
		
		sort(vx.begin(),vx.end());
		sort(vy.begin(),vy.end());
		
		int cur = 0;
		
		for(int i=0;i<vx.size();i++){
			if(i)
				if(vx[i].first != vx[i-1].first)
					cur++;
				int id = abs(vx[i].second) - 1;
				if(vx[i].second < 0)
					X2[id] = cur;
				else
					X1[id] = cur;
		}
		
	//	debug("ok\n");
		
		cur = 0;
		
		for(int i=0;i<vy.size();i++){
			if(i)
				if(vy[i].first != vy[i-1].first)
					cur++;
				int id = abs(vy[i].second) - 1;
				if(vy[i].second < 0)
					Y2[id] = cur;
				else
					Y1[id] = cur;
		}
		
		for(int i=0;i<n;i++)
			insert(0,2*n-1,1,i);
		
		
		for(int i=0;i<n;i++)
			if(X1[i] == 0 && Y1[i] == 0){
					dist[i] = 0;
					foi[i] = 1;
					Q.push(i);
					ini[i] = 1;
			}

		while(Q.size()){
			int u = Q.front();
			Q.pop();
			//debug("go %d\n",u);
			at = u;
			dcur = dist[at];
			go(0,2*n-1,1,X2[at],Y2[at]);
		}
		
		if(!foi[n-1]){
			printf("-1\n");
		//	assert(brute(n) == -1);
			return 0;
		}
		
		vector<int> ans;
		
		int t = n-1;
		ans.pb(t);
		while(!ini[t]){
			ans.pb(prec[t]);
			t = prec[t];
		}
		
		reverse(ans.begin(), ans.end());
		
		printf("%d\n",ans.size());
	//	assert(ans.size() == brute(n));
		
		for(int i=0;i<ans.size();i++){
			printf("%d ",1+ans[i]);
		//	if(i)
			//	assert(X2[ans[i]] >= X1[ans[i-1]] && Y2[ans[i]] >= Y1[ans[i-1]]);	
		}
		
		printf("\n");
		
}