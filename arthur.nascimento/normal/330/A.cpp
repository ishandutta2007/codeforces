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

char M[20][20];

main(){
    
    int r,c;
    scanf("%d%d\n",&r,&c);

    for(int i=0;i<r;i++){
    	for(int j=0;j<c;j++)
    		M[i][j] = getchar();
    	getchar();
}

     int a=r,b=c;

     for(int i=0;i<r;i++)
     	for(int j=0;j<c;j++)
     		if(M[i][j] == 'S'){
			a--;
			break;
     			}
     			
    for(int i=0;i<c;i++)
     	for(int j=0;j<r;j++)
     		if(M[j][i] == 'S'){
			b--;
			break;
     			} 	

       printf("%d\n",a*c + b*r - a*b);
       }