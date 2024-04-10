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
#define maxn 1001000            
#define mod 1000000007
 
using namespace std;

long long v[maxn];
long long pref[maxn];
long long suf[maxn];

main(){
    
        long long n,k,x;
        cin >> n >> k >> x;
        
        for(int i=0;i<n;i++)
            scanf("%I64d",v+i);
        
        pref[0] = v[0];
        for(int i=1;i<n;i++)
            pref[i] = pref[i-1] | v[i];
            
        suf[n-1] = v[n-1];
        for(int i=n-2;i>=0;i--)
            suf[i] = suf[i+1] | v[i];
            
        long long ans = 0;
        
        for(int i=0;i<n;i++){
            
            long long u = v[i];
            for(int j=0;j<k;j++)
                u = u * x;
           
           long long t = 0;
           if(i) t |= pref[i-1];
           if(i != n-1) t |= suf[i+1];
           t |= u;
           
           ans = max(ans,t);
           
       }
       
       cout << ans << endl;
       
       
}