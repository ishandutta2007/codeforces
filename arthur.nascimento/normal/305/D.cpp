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

int p[maxn];

main(){

		p[0] = 1;
		for(int i=1;i<maxn;i++) p[i] = (2*p[i-1]) % mod;

		int n,m,k,a,b,t;
		scanf("%d%d%d",&n,&m,&k);
		
		a = n-1;
		b = -1;
		t = 0;
		int ok = 1;

		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d%d",&x,&y), x--, y--;
			if(y == x+1) continue;
			if(y != x+k+1) ok = 0;
			a = min(a,x);
			b = max(b,x);
			t++;
		}

		int ans = 0;;
		if(t == 0) ans = 1;
		
		for(int i=0;i<n;i++){
			if(i > a || i+k+1 >= n) continue;
			if(b-i > k) continue;
			int f = min(n-k-2,i+k)-i+1;
			f -= t;
			if(i != a) f--;
			debug("%d %d\n",i,f);
			ans += p[f];
			ans %= mod;
		}

		if(!ok) ans = 0;
		cout << ans << endl;

}