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

char str[110];

int M[2000][2000];

int f(int a){
 
 if(abs(a) <= 2000)return 0;
 
 if(a > 0)return a - 1000;
 
 return a + 1000;}
 
    
    

main(){
       
       int a,b;
       scanf("%d%d",&a,&b);
       
       scanf(" %s",str);
       
       int x = 1000;
       int y = 1000;
       M[x][y] = 1;
       
       for(int i=0;i<strlen(str);i++){
               
               if(str[i] == 'U')y++;
               if(str[i] == 'D')y--;
               if(str[i] == 'L')x--;
               if(str[i] == 'R')x++;
               
               M[x][y] = 1;
               }
       int dx = x - 1000;
       int dy = y - 1000;
       
       if(dx == 0 && dy == 0){
             
             printf("%s\n",M[a+1000][b+1000]?"Yes":"No");
             return 0;
             }
       
       int resp = 0;
       int p = (dx) ? f(a)/dx : f(b)/dy;
       
       x = p*dx;
       y = p*dy;
       
       for(int i=0;i<2000;i++){
               
               int tx = a - x;
               int ty = b - y;
               
               if(tx > -1000 && tx < 1000 && ty > -1000 && ty < 1000)
                     resp |= M[tx+1000][ty+1000];
               
               x += dx;
               y += dy;
               }
               
               
       printf("%s\n",resp?"Yes":"No");
    
       }