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
#define maxn 1010

using namespace std;

int h[maxn];
int w[maxn];

int comp(int a,int b){
	return w[a]-h[a] > w[b]-h[b];
}

main(){

		int n;
		scanf("%d",&n);

		int t = 0;
		for(int i=0;i<n;i++){
			scanf("%d%d",w+i,h+i);
			t = max(t,min(w[i],h[i]));
		}

		long long ans = -1;
		
		for(int i=t;i<=1000;i++){

			int vira = 0;
			long long W=0, H=i;
			vector<int> v;
			
			for(int j=0;j<n;j++){
				if(w[j] > i || h[j] > i){
					if(w[j] > i) W += w[j];
					else W += h[j], vira++;
				}
				else
					v.pb(j);
			}

			if(2*vira > n) continue;

			sort(v.begin(), v.end(), comp);
			for(int j=0;j<v.size();j++){
				if(vira < n/2 && w[v[j]] > h[v[j]])
					W += h[v[j]], vira++;
				else
					W += w[v[j]];
			}

			if(ans == -1 || H*W < ans)
				ans = H*W;

		}

		cout << ans << endl;

}