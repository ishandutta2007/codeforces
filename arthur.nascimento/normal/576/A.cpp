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
#define maxn 200200			
#define mod 1000000007
 
using namespace std;

main(){

		int n;
		scanf("%d",&n);
		vector<int> ans;
	

		for(int i=2;i<=n;i++){

			int ok = 1;
			int u = -1;
			int aux = i;
			for(int j=2;aux != 1;j++) if(aux%j == 0){
				if(u+1) ok = 0;
				u = j;
				while(aux%j == 0) aux /= j;
			}
			if(!ok) continue;
			ans.pb(i);
		}

		printf("%d\n",ans.size());

		for(int i=0;i<ans.size();i++)
			printf("%d ",ans[i]);

}