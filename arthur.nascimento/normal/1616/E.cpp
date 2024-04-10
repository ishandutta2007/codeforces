#include <bits/stdc++.h>

 

#define maxn 100100	

#define pb push_back

#define debug 

#define mid ((ini+fim)/2)

#define ll long long

#define pii pair<int,int>

 

using namespace std;

int T[maxn];

void upd(int id,int x){
	id++;
	while(id < maxn){
		T[id] += x;
		id += id&-id;
	}
}

ll qry(int id){
	ll ret = 0;
	id++;
	while(id){
		ret += T[id];
		id -= id&-id;
	}
	return ret;
}

char s[maxn];
char t[maxn];

int mrk[maxn];

vector<int> occ[140];
int ptr[140];

main(){

	int nt;
	scanf("%d",&nt);
	while(nt--){

		int n;
		scanf("%d",&n);

		scanf(" %s %s",s,t);

		for(int i=0;i<140;i++){
			occ[i].clear();
			ptr[i] = 0;
		}

		for(int i=0;i<n;i++){
			occ[s[i]].pb(i);
		}

		ll cur = 0;

		for(int i=0;i<n;i++) upd(i,1);

		ll ans = 1e15;

		for(int i=0;i<n;i++){

			debug("i %d\n",i);

			int lo = t[i];

			int best = n+1;

			for(int j='a';j<lo;j++){
				while(ptr[j] < occ[j].size() && mrk[occ[j][ptr[j]]] ) ptr[j]++;
				if(ptr[j] < occ[j].size()) best = min(best,occ[j][ptr[j]]);
			}

			if(best <= n) ans = min(ans, cur + qry(best-1));

			while(ptr[lo] < occ[lo].size() && mrk[occ[lo][ptr[lo]]]) ptr[lo]++;
			if(ptr[lo] == occ[lo].size()) break;

			int pos = occ[lo][ptr[lo]];

			debug("get %d\n",pos);

			upd(pos,-1);
			cur += qry(pos-1);


			mrk[pos] = 1;
		
		}

		if(ans > 1e14) printf("-1\n");
		else printf("%lld\n",ans);

		for(int i=0;i<n;i++){
			if(mrk[i] == 0) upd(i,-1);
			mrk[i] = 0;
		}

	}

}