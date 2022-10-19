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


main(){
       
       int a,b;
       scanf("%d%d",&a,&b);
       
       printf("%d\n",a+b-1);
       
       for(int i=1;i<=b;i++)
               printf("1 %d\n",i);
               
       for(int i=2;i<=a;i++)
               printf("%d 1\n",i);
       
      }