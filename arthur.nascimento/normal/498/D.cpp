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
#define pll pair<long long,long long>
#define pip pair<long long,pll>

#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back

#define maxn 100100
#define mod 1000000007

using namespace std;

int T[66][4*maxn];

void update(int init,int fim,int p,int pos,int val){

	if(init > pos || fim < pos) return;

	if(init == fim){
		for(int i=0;i<60;i++){
			if(i%val == 0)
				T[i][p] = 2;
			else
				T[i][p] = 1;
		}
		return;
	}

	int mid = (init+fim)/2;

	update(init,mid,2*p,pos,val);
	update(mid+1,fim,2*p+1,pos,val);

	for(int i=0;i<60;i++)
		T[i][p] = T[i][2*p] + T[(i+T[i][2*p])%60][2*p+1];

}

int ans;

void query(int init,int fim,int p,int x,int y){

	if(init > y || fim < x) return;

	if(init >= x && fim <= y){
	
		debug("+ %d..%d (%d)\n",init,fim,T[ans%60][p]);
		ans += T[ans%60][p];
		
		return;

	}

	int mid = (init+fim)/2;
	query(init,mid,2*p,x,y);
	query(mid+1,fim,2*p+1,x,y);

}


main(){

		int n,q;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			int u;
			scanf("%d",&u);
			update(0,n-1,1,i,u);
		}

		scanf("%d",&q);

		while(q--){

				char ch;
				scanf(" %c",&ch);

				if(ch == 'A'){
					int x,y;
					scanf("%d%d",&x,&y), x--, y-=2;
					ans = 0;
					query(0,n-1,1,x,y);
					printf("%d\n",ans);
				}
				else {
					int x,y;
					scanf("%d%d",&x,&y), x--;
					update(0,n-1,1,x,y);
				}

		}

}