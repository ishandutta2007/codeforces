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
#define mod 1000000007
#define maxn 200200

using namespace std;

int v[2*500500];
int foi[2*500500];

main(){
    
        int n;
        scanf("%d",&n);
        
        for(int i=0;i<n;i++) scanf("%d",v+i);
        
        sort(v,v+n);
        
        int low = 0, up = n;
        
        while(low != up){
            
            int mid = (low+up+1)/2;
            
            int ok = 1;
            
            if(2*mid > n) ok = 0;
            
            for(int i=0;i<mid;i++)
                if(2*v[i] > v[n-mid+i]) ok = 0;
                
            if(ok)
                low = mid;
            else
                up = mid-1;
        
        }

        printf("%d\n",n-low);
        
}