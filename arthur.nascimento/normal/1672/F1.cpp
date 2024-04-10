#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define debug 
#define mid ((ini+fim)/2)
#define ll long long
#define pii pair<int,int>
using namespace std;

int f[maxn];
int v[maxn];
multiset<int> S[maxn];


main(){

	int nt;
	scanf("%d",&nt);

	while(nt--){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			scanf("%d",v+i);
			f[v[i]]++;
		}	

		vector<pii> vv;

		for(int i=1;i<=n;i++)
			if(f[i])
				vv.pb({f[i],i});

		sort(vv.begin(), vv.end());
		reverse(vv.begin(), vv.end());

		debug("vv "); for(pii i : vv )debug("%d,%d  ",i.first,i.second); debug("\n");

		vector<int> bd;

		int pos = 0;
		while(bd.size() < n){
			debug("pos %d num %d\n",pos,vv[pos].second);
			bd.pb(vv[pos].second);
			vv[pos].first--;
			pos++;
			if(pos >= vv.size() || vv[pos].first == 0) pos = 0;
		}

		for(int i : bd) debug("%d ",i); debug("\n");

		
		for(int i=0;i<n-1;i++){
			S[bd[i]].insert(bd[i+1]);
		}

		S[bd[n-1]].insert(bd[0]);

		for(int i=0;i<n;i++){
			int a = *S[v[i]].begin();
			printf("%d ",a);
			S[v[i]].erase(S[v[i]].begin());
		}
		printf("\n");

		for(int i=1;i<=n;i++){
			S[i].clear();
			f[i] = 0;
		}

	}

}