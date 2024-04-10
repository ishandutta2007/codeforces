#include <bits/stdc++.h>

using namespace std;

typedef double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 998244353;
const LL INF = 1LL * MX * MX;

LL d;
vector <int> cnt;
vector <LL> primes;

int n;
LL vals[N];
map <LL, int> id;

int dvs[N];
vector <PII> G[N];

int vis[N];
map <int, int> D[N];
map <int, int> M[N];

LL edge_weight(int fa, int fb){
	return dvs[fa] - dvs[fb];
}

void add(int &a, int b){
	a += b;
	if(a >= MX)
		a -= MX;
}

void Dijkstra(int s){
	priority_queue <PII> Q;
	Q.push({0, s});
	
	D[s][s] = 0;
	M[s][s] = 1;
	
	while(!Q.empty()){
		int u = Q.top().nd;
		Q.pop();
		
//		cerr << vals[s] << " " << vals[u] << " " << M[s][u] << " " << D[s][u] << "\n";
		
		if(vis[u] == s)
			continue;
		vis[u] = s;
		
		int _d = D[s][u];
		for(auto v: G[u]){
			if(!D[s].count(v.st) || D[s][v.st] > _d + v.nd){
				D[s][v.st] = _d + v.nd;
				M[s][v.st] = M[s][u];
				Q.push({-D[s][v.st], v.st});
			}
			else if(D[s][v.st] == _d + v.nd)
				add(M[s][v.st], M[s][u]);
		}
	}
}

void prepro(){
	LL tmp = d;
	for(int i = 2; 1LL * i * i <= tmp; ++i)
		if(tmp % i == 0){
			primes.push_back(i);
			cnt.push_back(0);
			
			while(tmp % i == 0){
				tmp /= i;
				cnt.back()++;
			}
		}
	
	if(tmp > 1){
		primes.push_back(tmp);
		cnt.push_back(1);
	}
	
	for(LL i = 1; i * i <= d; ++i)
		if(d % i == 0){
			vals[++n] = i;
			id[i] = n;

			if(d != i * i){
				vals[++n] = d / i;
				id[d / i] = n;
			}
		}
	
	for(int i = 1; i <= n; ++i){
		dvs[i] = 1;
		LL x = vals[i];

		for(auto v: primes){
			int mt = 1;
			while(x % v == 0){
				x /= v;
				++mt;
			}
			
			dvs[i] *= mt;
		}
	}
	
	for(int i = 1; i <= n; ++i)
		for(auto v: primes)
			if((d / vals[i]) % v == 0)
				G[i].push_back({id[vals[i] * v], edge_weight(id[vals[i] * v], i)});
	
/*	for(int i = 1; i <= n; ++i){
		printf("%lld -> ", vals[i]);
		for(auto v: G[i])
			printf("%lld %d :: ", vals[v.st], v.nd);
		puts("");
	}
	*/	
	
	Dijkstra(1);
}

int main(){
	scanf("%lld", &d);
	prepro();
	
	int q;
	scanf("%d", &q);
	
	while(q--){
		LL u, v;
		scanf("%lld %lld", &u, &v);
		LL nd = __gcd(u, v);
		int fu = id[u / nd], fv = id[v / nd];
		printf("%lld\n", 1LL * M[1][fu] * M[1][fv] % MX);
	}
	
	return 0;
}