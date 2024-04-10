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
#define mod 1000000007
#define maxn 101000
using namespace std;
typedef long long ll;

long long dp[maxn];

ll pos[maxn];
int val[maxn];

int ok[maxn];

vector<pll> v[maxn];


main(){

	ll h,n,m,k;
	cin >> h >> n >> m >> k;

	multiset<int> ans;

	for(int i=0;i<n;i++){
		scanf("%I64d%d",pos+i,val+i), pos[i]--;
		v[pos[i]%k].pb(pll(pos[i],i));
	}

	for(int i=0;i<k;i++)
		sort(v[i].begin(), v[i].end());

	for(int i=1;i<k;i++)
		dp[i] = h;

	while(v[0].size()){
		pii u = v[0][v[0].size()-1];
		v[0].pop_back();
		ans.insert(val[u.second]);
		ok[u.second] = 1;
	}

	while(m--){

		int t;
		scanf("%d",&t);

		if(t == 3){
			if(ans.size() == 0)
				printf("0\n");
			else {
				printf("%d\n",*--ans.end());
				ans.erase(--ans.end());
			}
		}
		if(t == 2){
			int u, dec;
			scanf("%d%d",&u,&dec), u--;
			if(ok[u])
				ans.erase(ans.find(val[u]));
			val[u] -= dec;
			if(ok[u])
				ans.insert(val[u]);
		}
		if(t == 1){

			ll a;
			cin >> a;
			
			priority_queue<pll> Q;

			for(int i=0;i<k;i++)
				Q.push(pll(-dp[i],i));

			while(Q.size()){

				pll u = Q.top();
				u.first *= -1;
				Q.pop();
				if(u.first == h)
					break;
				if(dp[(a+u.second)%k] > dp[u.second] + a){
					dp[(a+u.second)%k] = dp[u.second] + a;
					Q.push(pll(-dp[u.second]-a,(a+u.second)%k));
				}

			}

			for(int i=1;i<k;i++){
				while(v[i].size() > 0 && v[i][v[i].size()-1].first >= dp[i]){
					pii u = v[i][v[i].size()-1];
					v[i].pop_back();
					ok[u.second] = 1;
					ans.insert(val[u.second]);
				}
			}

		}

	}

}