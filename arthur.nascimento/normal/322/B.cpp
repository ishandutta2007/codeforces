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

#define min3(a,b,c) min(min(a,b),c)

using namespace std;


main(){
       
       int a,b,c;
       
       scanf("%d%d%d",&a,&b,&c);
       
       int r = 0;
       
       for(int i=0;i<3;i++)
       
               if(a >= i && b>=i && c>=i)
       r = max(r,  (a-i)/3 + (b-i)/3 + (c-i)/3 + i );
       
       
       
       printf("%d\n",r);
       
       }