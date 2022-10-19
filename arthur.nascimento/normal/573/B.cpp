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
#define maxn 100100
#define mod 1000000007

using namespace std;

int v[maxn];
int g[maxn];

main(){
        
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
                scanf("%d",v+i);
        int ans = 0;
        
        int at = 0;
        for(int i=n-1;i>=0;i--){
                at = min(at+1,v[i]);
                g[i] = at;
                debug("i %d at %d\n",i,at);
        }
        at = 0;
        for(int i=0;i<n;i++){
                at = min(at+1,v[i]);
                debug("i %d at %d\n",i,at);
                ans = max(ans,min(at,g[i]));
        }
        
        printf("%d\n",ans);
        
}