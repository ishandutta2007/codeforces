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

multiset<pii> livre;

multiset<int> maq[3];

int T[3];

main(){

		int k,n1,n2,n3;
		scanf("%d%d%d%d%d%d%d",&k,&n1,&n2,&n3,T,T+1,T+2);

		for(int i=0;i<n1;i++)
			maq[0].insert(0);
		for(int i=0;i<n2;i++)
			maq[1].insert(0);
		for(int i=0;i<n3;i++)
			maq[2].insert(0);

		for(int i=0;i<k;i++)
			livre.insert(pii(0,0));

		int ans = 0;

		while(livre.size()){

			pii u = *(livre.begin());
			livre.erase(livre.begin());

			ans = u.first;

			if(u.second == 3) continue;
			int y = u.second;

			int t = *(maq[y].begin());
			maq[y].erase(maq[y].begin());
			t = max(t,u.first);
			maq[y].insert(t + T[y]);

			livre.insert(pii(t + T[y],y+1));

		}

		printf("%d\n",ans);

}