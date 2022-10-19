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

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)
 
using namespace std;

int a[200100];
int b[200100];
int c[200100];

map<int,int> mp;
map<int,int> last;
set<int> ans;

main(){

	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);

	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<m;i++)
		scanf("%d",b+i);

	for(int i=0;i<p;i++){

		debug("i=%d\n",i);
		int sz=0;
		for(int j=i;j<n;j+=p)
			c[sz++] = a[j];

		for(int j=0;j<sz;j++)
			debug("%d ",c[j]);
		debug("\n");

		if(sz < m)
			continue;
			
		int qzero=m;

		for(int j=0;j<m;j++){

			if(last[b[j]] != i+1){
				mp[b[j]] = 0;
				last[b[j]] = i+1;}
				
			mp[b[j]]++;
			if(mp[b[j]] == 0)qzero++;
			if(mp[b[j]] == 1)qzero--;
			}

		for(int j=0;j<m;j++){

			debug("@%d ",c[j]);
			if(last[c[j]] != i+1){
			mp[c[j]] = 0;
			last[c[j]] = i+1;}
		
			mp[c[j]]--;
			if(mp[c[j]] == 0)qzero++;
			if(mp[c[j]] == -1)qzero--;

			}

		debug("! %d\n",qzero);
		if(qzero == m)
			ans.insert(i);

		for(int j=1;j+m-1<sz;j++){

				if(last[c[j+m-1]] != i+1){
				mp[c[j+m-1]] = 0;
				last[c[j+m-1]] = i+1;}

				mp[c[j+m-1]]--;
				if(mp[c[j+m-1]] == 0)qzero++;
				if(mp[c[j+m-1]] == -1)qzero--;

				if(last[c[j-1]] != i+1){
				mp[c[j-1]] = 0;
				last[c[j-1]] = i+1;}

				mp[c[j-1]]++;
				if(mp[c[j-1]] == 0)qzero++;
				if(mp[c[j-1]] == 1)qzero--;

				if(qzero == m)
					ans.insert(i + j*p);

				debug("j=%d qz=%d\n",j,qzero);

				}

	}

	printf("%d\n",ans.size());
	for(set<int> :: iterator it = ans.begin(); it != ans.end(); it++)
		printf("%d ",*it+1);

	}