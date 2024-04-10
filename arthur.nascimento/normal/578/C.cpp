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

int v[maxn];
long double r[maxn];

int n;


long double eval(long double t){

    for(int i=0;i<n;i++) r[i] = (long double) v[i] - t;
    
    long double ret = 0;
    long double cur = 0;
    
    long double f0 = 0;
    
    for(int i=0;i<n;i++){
        
        cur = max(f0,cur+r[i]);
        ret = max(ret,cur);
        
    }
    
    for(int i=0;i<n;i++) r[i] = -r[i];
    
    cur = 0;
    
    for(int i=0;i<n;i++){
        
        cur = max(f0,cur+r[i]);
        ret = max(ret,cur);
        
    }
    
    return ret;
    
}


main(){
        
        scanf("%d",&n);
        
        for(int i=0;i<n;i++)
            scanf("%d",v+i);
            
        long double low = -11000, up = 11000;
        
        for(int i=0;i<200;i++){
            
            long double mid1 = (2*low+up)/3;
            long double mid2 = (low+2*up)/3;
            
            long double A = eval(mid1);
            long double B = eval(mid2);
            
            if(A > B)
                low = mid1;
             else
                up = mid2;
       
        }
        
        printf("%.12lf\n",(double)eval(low));
        
}