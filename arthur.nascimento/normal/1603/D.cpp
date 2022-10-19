#include <bits/stdc++.h>

#define maxn 100100

#define ll long long

#define debug

#define pb push_back

#define pii pair<int,int>
#define mid ((ini+fim)/2)

using namespace std;

ll dp[20][maxn];

vector<int> divs[maxn];

int u[maxn];
int phi[maxn];

ll v[maxn];

ll beg;
int sz;
ll last;

ll dif[maxn];

int par[maxn];
int mx[maxn];
int mn[maxn];
int rk[maxn];

ll get_min(){
	return beg;
}

int find(int x){
	return par[x] = (x == par[x]) ? x : find(par[x]);
}

void merge(int a,int b){
	a = find(a);
	b = find(b);
	if(rk[a] < rk[b]) swap(a,b);
	par[b] = a;
	mn[a] = min(mn[a],mn[b]);
	mx[a] = max(mx[a],mx[b]);
	if(rk[a] == rk[b]) rk[a]++;
}

void sum(int k,ll s){

	k--;
	k = find(k+1);

	int a = mn[k] - 1;
	int b = mx[k];
	if(a < 0) return;

	beg += s;

	if(a == sz-1){
		last += s;
		return;
	}
	
	v[a] -= s;

	ll lst;

	while(v[a] <= 0){
		lst = v[a];
		ll cur = v[a];
		merge(a,a+1);
		b = a;
		a = mn[find(a)] - 1;
		if(a < 0){
			beg = beg + lst;
			return;
		}
		v[a] += cur;		
	}
}

void add(ll x){

	int a = sz - 1, b = sz;
	sz++;
	v[a] = x - last;
	last = x;

	ll lst;

	while(v[a] <= 0){
		lst = v[a];
		ll cur = v[a];
		merge(a,a+1);
		b = a;
		a = mn[find(a)] - 1;
		if(a < 0){
			beg = beg + lst;
			return;
		}
		v[a] += cur;		
	}
	
}

void debug_all(int n=10){
	printf("first %lld\n",beg);
	for(int i=0;i<sz;){
		i = mx[find(i)];
		printf("%d: %lld\n",i,v[i]);
		i++;
	}
	printf("last %lld\n\n",last);
}

main(){

	memset(dif,0,sizeof(dif));

	beg = last = 0;
	sz = 1;

	for(int i=0;i<maxn;i++)
		par[i] = mn[i] = mx[i] = i, rk[i] = 1;

	dp[0][0] = 0;
	
	for(int i=1;i<maxn;i++)
		dp[0][i] = 1e12, u[i] = 1;

	for(int i=1;i<maxn;i++){

		if(divs[i].size() == 1 && i > 1){
			u[i] = 1;
			for(int j=i;j<maxn;j+=i){
				u[j] *= -1;
				if((j/i) % i == 0) u[j] = 0;
			}
		}
	
		for(int j=i;j<maxn;j+=i)
			divs[j].pb(i), phi[j] += u[i] * (j/i);

	}

	phi[1] = 0;

	for(int k=1;k<20;k++){

		memset(dif,0,sizeof(dif));

		beg = last = 0;
		sz = 1;

		for(int i=0;i<maxn;i++)
			par[i] = mn[i] = mx[i] = i, rk[i] = 1;
		
		for(int i=1;i<maxn;i++){

			for(int d : divs[i])
				sum(d,phi[i/d]);

			dp[k][i] = get_min();

			add(dp[k-1][i]);
			
		}

	}

	int nt;
	scanf("%d",&nt);

	while(nt--){
		int n,k;
		scanf("%d%d",&n,&k);
		if(k >= 20)
			printf("%d\n",n);
		else
			printf("%lld\n",n+dp[k][n]);
	}
	
}