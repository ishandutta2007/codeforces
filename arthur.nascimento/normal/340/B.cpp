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

#define sq(x) ((x)*(x))
  
using namespace std; 
  
int x[330];
int y[330];

int ccw(int a,int b,int c){
       return (x[b]-x[a])*(y[c]-y[a]) - (y[b]-y[a])*(x[c]-x[a]);
       }

main(){ 
        
        int n;
        scanf("%d",&n);
        
        for(int i=0;i<n;i++)
                scanf("%d%d",x+i,y+i);
                
        double ans = 0;
                
        for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++){
                        
                        double e=0,d=0;
                        double A = sqrt(sq(x[j]-x[i]) + sq(y[j]-y[i]));
                        double B,C,p,area2;
                        
                        for(int k=0;k<n;k++){
                                if(k==i || k==j)
                                        continue;
                                
                                B = sqrt(sq(x[k]-x[i]) + sq(y[k]-y[i]));
                                C = sqrt(sq(x[k]-x[j]) + sq(y[k]-y[j]));
                                
                                p = (A+B+C)/2;

                                area2 = p*(p-A)*(p-B)*(p-C);
                                
                                if(ccw(i,j,k) > 0)
                                              e = max(e,area2);
                                else
                                              d = max(d,area2);
                                
                                }

                        if(e > eps && d > eps)        
                        ans = max(ans,sqrt(e)+sqrt(d));

                        }
                        
        printf("%lf\n",ans);
        }