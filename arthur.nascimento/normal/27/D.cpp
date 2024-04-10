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
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

int x[110];
int y[110];
char v[110];
int n,m;

int cruza(int a,int b){

	return (x[a] < x[b] && x[b] < y[a] && y[a] < y[b]) || (x[b] < x[a] && x[a] < y[b] && y[b] < y[a]);
}


main(){
    
	scanf("%d%d",&n,&m);

	for(int i=0;i<m;i++){
		scanf("%d%d",x+i,y+i);
		if(x[i] > y[i])
			swap(x[i],y[i]);
}

    	for(int i=0;i<m;i++){

		int get = -1;

		for(int j=0;j<m;j++){

			if(get == -1 && v[j] == 0)
				get = j;

			int ok = 0;
			for(int k=0;k<m;k++)
				if(cruza(k,j) && v[k])
					ok = 1;

			if(ok && v[j] == 0)
				get = j;
			}
		debug("get %d\n",get);
		int c=1,d=1;

		for(int j=0;j<m;j++)
			if(cruza(get,j) && v[j]){
				if(v[j] == 'i')
					c = 0;
				else 	d = 0;
				}
		if(c == 0 && d == 0){
			printf("Impossible\n");
			return 0;
			}
		if(c)
			v[get] = 'i';
		else    v[get] = 'o';
    		}

    		for(int i=0;i<m;i++)
    			printf("%c",v[i]);
}