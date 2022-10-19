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

#define inf 99999999999.
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
#define maxn 1001000

using namespace std;

int f[maxn];

main(){

        vector<int> v;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int u;
            scanf("%d",&u);
            f[u]++;
        }
        int ans = 0;
        for(int i=0;i<maxn;i++){
        	f[i+1] += f[i]/2;
        	f[i] %= 2;
        	ans += f[i];
        }

        cout << ans << endl;

}