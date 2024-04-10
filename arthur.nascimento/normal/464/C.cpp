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

#define inf (999999999)
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

char str[100100];
int v[100100];

vector<int> muda[100100];
long long tam[100100];

long long p10(long long k){

	if(k == 0) return 1;
	if(k == 1) return 10;
	long long u = p10(k/2);
	u = (u*u)%mod;
	if(k%2) u = (u*10)%mod;
	return u;
}


queue<int> orig[10];
queue<pii> pos[10];

long long val[100100];

void getstr(){
	char ch;
	int t = 0;
	while((ch=getchar()) != '\n'){
		str[t++] = ch;
	}
	str[t] = 0;

}

main(){

		scanf("%s",str);

		int n = strlen(str);

		for(int i=0;i<n;i++){
			v[i] = str[i]-'0';
			orig[v[i]].push(i);
		}

		int q;
		scanf("%d",&q);

		for(int i=1;i<=q;i++){

			char dig;
			scanf(" %c->",&dig);
			getstr();

			
			dig -= '0';
			debug("dig = %d str = %s\n",dig,str);
			int m = strlen(str);

			tam[i] = m;

			while(orig[dig].size()){

				debug("lol i=%d\n",i);
				int u = orig[dig].front();
				orig[dig].pop();
				v[u] = -i;

			}

			while(pos[dig].size()){

				pii u = pos[dig].front();
				pos[dig].pop();
				muda[u.first][u.second] = -i;
				//tam[u.first] += m-1;

			}

			for(int j=0;j<m;j++){
				muda[i].pb(str[j]-'0');
				pos[str[j]-'0'].push(pii(i,j));
			}
			

		}

		for(int i=q;i>=1;i--){

			long long t = 0;

			for(vector<int> :: iterator it = muda[i].begin(); it < muda[i].end(); it++){

				if(*it >= 0)
					t = (t*10+*it) % mod;
				else {
					t = t * p10(tam[-*it]);
					t %= mod;
					t = (t+val[-*it]) % mod;
					tam[i] += tam[-*it]-1;
					tam[i] %= mod-1;
				}

			}

			val[i] = t;

		}

		debug("val[2] = %I64d\n",val[1]);

		long long ans = 0;
		for(int i=0;i<n;i++){

			debug("ans = %I64d\n",ans);

			if(v[i] >= 0)
				ans = (10*ans+v[i])%mod;
			else{
				debug("+= 10^%I64d + %I64d\n",tam[-v[i]],val[-v[i]]);
				debug("v[i] = %d\n",v[i]);
				ans = ans * p10(tam[-v[i]]);
				ans %= mod;
				ans = (ans+val[-v[i]]) % mod;
			}
		}

		printf("%I64d\n",ans);

	}