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

struct edge {
		int idx,p,a,b,lig;
}

E[maxn];

bool comp1(edge a,edge b){
	if(a.p == b.p)
		return a.lig > b.lig;
	return a.p < b.p;
}

bool comp2(edge a,edge b){
	return a.idx < b.idx;
}

main(){
		
	int n,m;
	scanf("%d%d",&n,&m);
	int lig = 0;
	
	for(int i=0;i<m;i++){
		int u;
		scanf("%d%d",&E[i].p,&u);
		if(u) lig++, E[i].lig = 1;
		E[i].idx = i;
	
	}
	
	sort(E,E+m,comp1);
	
	if(lig != n-1){
		printf("-1\n");
		return 0;
	}
	
	set<pii> pode;
	
	int ss = 0;
	for(int i=0;i<m;i++){
			debug("go %d\n",E[i].idx);
		if(E[i].lig){
			ss++;
			E[i].a = ss-1;
			E[i].b = ss;
			for(int j=0;j<ss-1 && pode.size() <= m;j++)
				pode.insert(pii(j,ss));
			continue;
		}

		if(pode.size() == 0){
			printf("-1\n");
			return 0;
		}
			
		pii k = *pode.begin();
		pode.erase(k);
		E[i].a = k.first;
		E[i].b = k.second;
	}
	
	sort(E,E+m,comp2);
	
	for(int i=0;i<m;i++)
		printf("%d %d\n",E[i].a+1,E[i].b+1);

}