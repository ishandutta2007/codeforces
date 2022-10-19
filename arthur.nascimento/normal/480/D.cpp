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
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

struct caixa {
	int ti,tf,w,s,val;
	void read(){
		scanf("%d%d%d%d%d",&ti,&tf,&w,&s,&val);
	}
	bool operator<(caixa comp)const{
		if(tf == comp.tf)
			return ti > comp.ti;
		return tf < comp.tf;
	}
}

v[550];

vector<int> sai[1010];

int dp[550][1010];
int dp2[1010];

main(){

		int n,s;
		scanf("%d%d",&n,&s);

		for(int i=0;i<n;i++)
			v[i].read();

		sort(v,v+n);

		for(int i=0;i<n;i++)
			sai[v[i].tf].pb(i);

		for(int i=0;i<=s;i++)
			for(int j=0;j<n;j++){

				dp2[v[j].ti] = 0;
				
				for(int k=v[j].ti;k<=v[j].tf;k++){

					if(k > v[j].ti) dp2[k] = dp2[k-1];

					for(vector<int> :: iterator it = sai[k].begin(); it < sai[k].end(); it++){
						int p = min(i-v[*it].w,v[*it].s);
						if(p >= 0 && v[*it].ti >= v[j].ti && *it != j)
							dp2[k] = max(dp2[k], dp[*it][p] + dp2[v[*it].ti]);
							
					}		
					
				}
			
			dp[j][i] = v[j].val + dp2[v[j].tf];
			debug("dp[%d][%d] = %d\n",j,i,dp[j][i]);

			}

		memset(dp2,0,sizeof(dp2));

		for(int i=0;i<=2*n;i++){

				dp2[i] = 0;
				if(i) dp2[i] = dp2[i-1];
				for(vector<int> :: iterator it = sai[i].begin(); it < sai[i].end(); it++){
					int p = min(s-v[*it].w,v[*it].s);
					if(p >= 0)
						dp2[i] = max(dp2[i],dp[*it][p] + dp2[v[*it].ti]);
				}

		}

		printf("%d\n",dp2[2*n]);

}