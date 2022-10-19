#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 200200

typedef long long ll;
using namespace std;

int v[maxn];

int T[5][maxn];
int sz[5];
int ptr[5];

int extra[5];
int add[5];

void corner(int n,int k,int a){

	debug("corner\n");
	for(int i=0;i<n;i++)
		scanf("%d",v+i);
	sort(v,v+n);
	reverse(v,v+n);

	ll ans = (ll)inf*inf;

	ll sum = 0;
	for(int i=1;i<k;i++)
		sum += v[i];
		
	for(int i=0;i+k<=n;i++){
		ans = min(ans,(ll)(k-1)*v[i]-sum);
		sum -= v[i+1];
		sum += v[k+i];
	}

	cout << ans * a << endl;

	exit(0);
}

main(){

	int n,k,a1,a5;
	scanf("%d%d%d%d",&n,&k,&a5,&a1);

	if(5*a1 <= a5)
		corner(n,k,a1);

	ll ans = (ll)inf*inf;

	for(int i=0;i<n;i++){
		scanf("%d",v+i);
		v[i] += 1000000001;
	}

	for(int mod=0;mod<5;mod++){

		debug("mod %d\n",mod);

		for(int i=0;i<5;i++)
			sz[i] = ptr[i] = 0;
		for(int i=0;i<n;i++)
			T[v[i]%5][sz[v[i]%5]++] = v[i];

		vector<int> opt;

		for(int i=0;i<n;i++){
			int u = v[i];
			while(u%5 != mod) u++;
			opt.pb(u);
		}

		for(int i=0;i<5;i++){
			sort(T[i],T[i]+sz[i]);
			reverse(T[i],T[i]+sz[i]);
		}

		sort(opt.begin(), opt.end());
		reverse(opt.begin(), opt.end());

		multiset<int> Q;

		int cur = 0;
		ll cand  = 0;

		for(int i=0;i<5;i++){
			int u = i;
			extra[i] = 0;
			add[i] = 0;
			while(u%5 != mod){
				u++;
				add[i]++;
				extra[i] += a1;
			}
		}

		for(int i=0;i<n;i++){

			int AT = opt[i];
			debug("AT %d\n",AT);

			while(cur < k){	

				int pegou = 0;
				int best;
				ll valbest = (ll)inf*inf;

				for(int j=0;j<5;j++){
					while(ptr[j] < sz[j] && T[j][ptr[j]] > AT) ptr[j]++;
					if(ptr[j] != sz[j]){
						ll u = extra[j] + (ll) a5 * ((AT-(T[j][ptr[j]]+add[j]))/5);
						if(pegou == 0 || u < valbest){
							valbest = u;
							best = j;
						}
						pegou = 1;
					}
				}

				if(pegou == 0)
					break;

				debug("+ %d\n",T[best][ptr[best]]);
				cand += valbest;
				debug("cand %d\n",(int)cand);
				cur++;
				Q.insert(T[best][ptr[best]]);
				ptr[best]++;

			}

			if(cur < k)
				break;

			ans = min(ans,cand);
			debug("!!! %d\n",(int) cand);

			if(i == n-1) break;
			
			int nxt = opt[i+1];debug("nxt %d\n",nxt);

			while(Q.size()){
				int u = *(--Q.end());
				if(u <= nxt) break;
				cur--;
				cand -= extra[u%5] + (ll) a5 * ((AT-(u+add[u%5]))/5);
				debug("- %d\n",u);
				debug("cand %d\n",(int)cand);
				Q.erase(Q.find(u));
			}

			cand -= (ll) Q.size() * a5 * ((AT-nxt)/5);
			debug("cand := %d\n",(int)cand);

		}

	}

	cout << ans << endl;

}