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

#define sq(x) ((x)*(x))
#define pb push_back

using namespace std;

int out(pii k,int n,int m){
	if(k.first < 0 || k.first > n || k.second < 0 || k.second > m) return 1;
	return 0;
}

double dist(pii a,pii b){
	return sqrt( sq(a.first-b.first) + sq(a.second-b.second));
}

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		if(n == 0)
			printf("0 1\n0 %d\n0 0\n0 %d\n",m,m-1);
		else if(m == 0)
			printf("1 0\n%d 0\n0 0\n%d 0\n",n,n-1);
		else {

			 vector<pii> v1;
			 for(int i=0;i<8;i++) for(int j=0;j<8;j++)
			 	v1.pb(pii(i,j));
			 vector<pii> v2;
			 for(int i=0;i<8;i++) for(int j=0;j<8;j++)
			 	v2.pb(pii(n-i,m-j));

			 vector<pii> ans;
			 double best = 0;

			 for(int i=0;i<64;i++)
			 	for(int j=0;j<64;j++)
			 		for(int k=0;k<64;k++)
			 			for(int l=0;l<64;l++){

							if(i==j || k==l)continue;
							if(v1[i]==v2[k] || v1[i]==v2[l])continue;
			 				if(v1[j]==v2[k] || v1[j]==v2[l])continue;
			 				if(out(v1[i],n,m)) continue;
			 				if(out(v1[j],n,m)) continue;
			 				if(out(v2[k],n,m)) continue;
			 				if(out(v2[l],n,m)) continue;
			 				double dd = dist(v1[i],v2[k]) + dist(v2[k],v1[j]) + dist(v1[j],v2[l]);
			 				if(dd > best){
			 					best = dd;
			 					ans.clear();
			 					ans.pb(v1[i]);
			 					ans.pb(v2[k]);
			 					ans.pb(v1[j]);
			 					ans.pb(v2[l]);
			 				}
					}

				for(int i=0;i<4;i++)
					printf("%d %d\n",ans[i].first,ans[i].second);
	}

}