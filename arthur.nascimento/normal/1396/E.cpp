#include <bits/stdc++.h>

#define maxn 100100

#define maxK 4100

#define ll long long

#define pb push_back

#define pii pair<int,int>

#define mod 1000000007 

#define debug(args...) //fprintf(stderr,args)

using namespace std;



vector<int> L[maxn];

int sub[maxn];

int h[maxn];

int anc[maxn];

int sz[maxn];


int foi[maxn];
int pre[maxn];
int cnt = 0;


void dfs(int x,int p=0){

	sub[x] = 1;

	for(int i : L[x])

		if(i != p){

			dfs(i,x);

			sub[x] += sub[i];

	}

}



vector<pii> match[maxn];

int W;



int dfs1(int x,int p,int br){
	sz[br]++;
	pre[x] = cnt++;

	if(p+1)

		h[x] = 1 + h[p];

	anc[x] = p;
	vector<int> v;

	for(int i : L[x])

		if(i != p){

			int u = dfs1(i,x,(p == -1) ? i : br);

			if(u+1)

				v.pb(u), W++;

		}

	v.pb(x);

	for(int i=0;i+1<v.size();i+=2){

		match[br].pb({v[i],v[i+1]});
		debug("+ %d~%d at %d\n",v[i],v[i+1],br);
	}

	if(v.size()%2 == 1)

		return v[v.size()-1];

	else 

		return -1;

}



int lca(int a,int b){

	if(h[a] < h[b]) return a;

	if(h[a] > h[b]) return b;

	return anc[a];

}	



main(){



	int n;

	ll k;

	scanf("%d%lld",&n,&k);



	for(int i=0;i<n-1;i++){

		int a,b;

		scanf("%d%d",&a,&b), a--, b--;

		L[a].pb(b);

		L[b].pb(a);

	}



	dfs(0);



	int ts = 0, p = 0;



	while(1){


		debug("ts %d\n",ts);
		

		if(ts > 0 && L[ts].size() == 1) break;

		int mx = -1;

		for(int i : L[ts])

			if(i != p){

				if(mx == -1 || sub[i] > sub[mx])

					mx = i;

			}

			

		if(2*sub[mx] >= n){
			p = ts;

			ts = mx;
		}

		else break;

		

	}



	dfs1(ts,-1,ts);



	ll cur = 0;

	for(int i=0;i<n;i++)

		cur += h[i];



	set<pii> S;

	for(int i : L[ts]){

		S.insert({sz[i],i});

		debug("ins %d %d\n",sz[i],i);
	}


	for(int i=0;i<n;i++)

		sort(match[i].begin(), match[i].end(), [](pii x,pii y){

			return min(h[x.first],h[x.second]) < min(h[y.first],h[y.second]);

		});



	if(k > cur || k < W || k%2 != cur%2){

		printf("NO\n");

		return 0;

	}



	vector<pii> ans;



	while(cur > k){

		debug("cur %lld\n",cur);
		pii u = *--S.end();

		S.erase(u);

		int br = u.second;

		pii p = match[br][match[br].size()-1];
		debug("p %d %d\n",p.first,p.second);

		match[br].pop_back();

		int dec = 2 * h[lca(p.first,p.second)];
		debug("dec %d\n",dec);

		if(cur-dec >= k){

			cur -= dec;

			ans.pb(p);
			foi[p.first] = foi[p.second] = 1;
			sz[br] -= 2;

			S.insert({sz[br],br});
			continue;

		}
		int x = p.first;
		if(h[p.first] < h[p.second]) x = p.second;
		int y = x;
		while(cur - 2 * h[y] < k)
			y = anc[y];
		debug("%lld - 2 * %d = %lld\n",cur,h[y],k);		
		ans.pb({x,y});
		foi[x] = foi[y] = 1;
		cur = k;
		

	}

	vector<int> outros;
	for(int i=0;i<n;i++)
		if(!foi[i])
			outros.pb(i);

	sort(outros.begin(), outros.end(), [](int i,int j){
		return pre[i] < pre[j];
	});

	for(int i=0;i<outros.size()/2;i++)
		ans.pb({outros[i],outros[i+outros.size()/2]});

	printf("YES\n");
	for(pii i : ans)
		printf("%d %d\n",i.first+1,i.second+1);

	

}