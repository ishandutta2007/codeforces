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
 
using namespace std;

int v[5050];
int q[5050];

int t[5050];
int a[5050];
int b[5050];
int c[5050];

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++)
			v[i] = 50000000;

		for(int i=0;i<m;i++)
			scanf("%d%d%d%d",t+i,a+i,b+i,c+i);

		int ok = 1;

		for(int i=m-1;i>=0;i--){

			a[i]--;
			b[i]--;
	
			if(t[i] == 1){
				for(int j=a[i];j<=b[i];j++)
					v[j] -= c[i];
				continue;
				}

			int tem = 0;
			for(int j=a[i];j<=b[i];j++){
				if(v[j] >= c[i])
					tem = 1;
				v[j] = min(v[j],c[i]);
				}

			if(!tem)
				ok = 0;


}
		for(int i=0;i<n;i++)
			q[i] = v[i];

		for(int i=0;i<m;i++){

			if(t[i] == 1){
				for(int j=a[i];j<=b[i];j++)
					q[j] += c[i];
				continue;
				}

			int mm = -999999999;

			for(int j=a[i];j<=b[i];j++)
				mm = max(mm,q[j]);

			if(mm != c[i])
				ok = 0;
			

			}

		if(!ok)
			printf("NO\n");

		else {

			printf("YES\n");
			for(int i=0;i<n;i++)
				printf("%d ",v[i]);
			
			}


}