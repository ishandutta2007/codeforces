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

#define inf (9999999999999999LL)
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
#define mod 805306457
#define maxn 200200

using namespace std;

long long hash0[30][maxn];
long long hs[30];

long long pw[maxn];

char s[maxn];
char t[maxn];

int oc[30];
int foi[30];
int qual[30];
int qual2[30];

#define chl 26

main(){

		memset(oc,-1,sizeof(oc));
		pw[0] = 1;
		for(int i=1;i<maxn;i++)
			pw[i] = (pw[i-1] * 37) % mod;

		int n,m;
		scanf("%d%d",&n,&m);
		scanf(" %s %s",s,t);

		for(int i=0;i<chl;i++){
			char ch = i + 'a';
			long long u = 0;
			for(int j=0;j<m;j++){
				u = u * 37;
				if(s[j] == ch) u++;
				u %= mod;
			}
			hash0[i][0] = u;
			debug("hash [%c][%d] = %I64d\n",ch,0,u);
			for(int j=m;j<n;j++){
				u = u * 37;
				if(s[j] == ch) {u++; debug("!%d ",j);}
				if(s[j-m] == ch) u -= pw[m];
				u = (u%mod+mod)%mod;
				hash0[i][j-m+1] = u;
				debug("hash [%c][%d] = %I64d\n",ch,j-m+1,u);
			}
		}

		for(int i=0;i<chl;i++){
			char ch = i + 'a';
			long long u = 0;
			for(int j=0;j<m;j++){
				u = u * 37;
				if(t[j] == ch) u++;
				u %= mod;
			}
			hs[i] = u;
			debug("hs[%c] = %I64d\n",ch,hs[i]);
		}

		for(int i=0;i<m;i++)
			oc[t[i]-'a'] = i;

		vector<int> ans;

		for(int i=0;i<=n-m;i++){
		
			memset(foi,0,sizeof(foi));
			debug("i = %d\n",i);

			int ok = 1;

			for(int j=0;j<chl;j++) if(oc[j]+1){
			 	int par = s[oc[j]+i]-'a';
			 	debug("par[%c] = %c\n",j+'a',par+'a');
			 	//if(foi[j] && qual[j] != par){ok = 0;debug("@");}
			 	//if(par < j && qual2[par] != j){ok = 0;debug("@");}
			 	//if(foi[par]) ok = 0;
			 	foi[par] = 1;
			 	qual[par] = j;
			 	qual2[j] = par;
			 	debug("cmp %I64d %I64d\n",hash0[par][i] , hs[j]);
			 	if(hash0[par][i] != hs[j]) ok = 0;
			 	if(hash0[j][i] != hs[par]) ok = 0;
			 }

			 if(ok) ans.pb(i);

		}

		printf("%d\n",ans.size());

		for(int i=0;i<ans.size();i++)
			printf("%d ",ans[i]+1);

}