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
#define maxn 1001000

using namespace std;

int divs[maxn+1];

vector<int> L[maxn+1];
long long last[maxn+1];
long long v[maxn+1];
int in[maxn+1];
long long aux[maxn+1];

main(){

		for(int i=2;i<maxn;i++) if(divs[i] == 0) 

			for(int j=1;i*j<maxn;j++) divs[i*j] = i;

		for(int i=2;i<maxn;i++) if(divs[i] == i){

			int t = i-1;
			while(t-1)
				L[i].pb(divs[t]), t /= divs[t];

		}

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			long long p,t;
			scanf("%I64d%I64d\n",&p,&t);
			v[p] += t;
		}

		long long k;
		scanf("%I64d",&k);

		for(int i=0;i<min(20LL,k);i++){

			for(int j=1;j<maxn;j++) aux[j] = v[j];

			for(int j=1;j<maxn;j++) if(v[j]){

				aux[j]--;
				for(vector<int> :: iterator it = L[j].begin(); it < L[j].end(); it++)
					aux[*it]++;

			}

			for(int j=1;j<maxn;j++) v[j] = aux[j];

		}

		for(int i=2;i<maxn;i++) if(v[i]){

			in[i]--;
			for(vector<int> :: iterator it = L[i].begin(); it < L[i].end(); it++)
				in[*it]++;

			last[i] = min(20LL,k);

		}

		set<pll> st;

		long long foi = min(20LL,k);

		for(int i=2;i<maxn;i++) if(in[i] == -1) {

			long long t = foi + v[i];
			st.insert(pll(t,i));

		}

		while(foi < k && st.size()){

			pll u = *st.begin();
			st.erase(u);

			long long muda = u.first - foi;

			if(u.first >= k){
				foi = k;
				continue;
			}

			foi = u.first;

			int p = u.second;
			v[p] = 0;
			in[p] = 0;

			for(vector<int> :: iterator it = L[p].begin(); it < L[p].end(); it++) {

				v[*it] += (foi-last[*it]) * in[*it];
							
				last[*it] = foi;
				in[*it]--;

				if(in[*it] == -1){
					long long t = foi + v[*it];
					st.insert(pll(t,*it));
				}

			}

		}

		vector<pll> ans;

		for(int i=2;i<maxn;i++){

			if(k <= 20) in[i] = 0;
			long long q = v[i] + (k-last[i]) * in[i];
			if(q)
				ans.pb(pll(i,q));

		}

		sort(ans.begin(),ans.end());

		printf("%d\n",ans.size());

		for(int i=0;i<ans.size();i++)
			printf("%I64d %I64d\n",ans[i].first,ans[i].second);

}