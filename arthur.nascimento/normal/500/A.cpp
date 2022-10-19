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
#define maxn 100100

using namespace std;

int v[maxn];

main(){
        
        int n,k;
        scanf("%d%d",&n,&k);
        int ok = 0;
        
        for(int i=0;i<n-1;i++)
            scanf("%d",v+i);
            
        int pos = 0;
        while(pos != n-1){
            if(pos == k-1) ok = 1;
            pos += v[pos];
           }
        if(k == n) ok = 1;
        if(ok)printf("YES\n");
        else printf("NO\n");
        
}