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

long long h[maxn];
long long a[maxn];
int v[maxn];

main(){

		long long n,m,k,p;
		cin >> n >> m >> k >> p;

		long long amax = 0;

		for(int i=0;i<n;i++){
			cin >> h[i] >> a[i];
			amax = max(amax,a[i]);
		}

		long long low = amax, up = 10000000000000000LL;


		while(low != up){

			long long mid = (low+up)/2;

			long long tot = 0;

			for(int i=0;i<n;i++){
				if(mid >= h[i] + m*a[i]) continue;
				tot += (h[i]+m*a[i]-mid)/p;
				if((h[i]+m*a[i]-mid)%p) tot++;
			}

			int ok = 0;
			debug("tot = %I64d\n",tot);

			if(tot <= m*k){

				for(int i=0;i<m;i++) v[i] = 0;

				for(int i=0;i<n;i++){
					debug("i = %d\n",i);
					int last = 0;
					if(mid >= h[i] + m*a[i]) continue;

					long long t = (h[i]+m*a[i]-mid)/p;
					if((h[i]+m*a[i]-mid)%p) t++;

					for(int j=0;j<t;j++){
			
						long long x = (p*j+mid)/a[i]-1;
						x = m-x;
						x--;
						if(x<0)x=0;
						v[x]++;
						debug("j=%d x=%I64d\n",j,x);
							
					}

				}

				int s = 0;
				ok = 1;
				for(int i=m-1;i>=0;i--){
					s += v[i];
					if(s > k * (m-i)) ok = 0;
				}

			}

			debug("mid %I64d ok %d\n",mid,ok);
			if(ok)
				up = mid;
			else
				low = mid+1;

		}

		cout << low << endl;

}