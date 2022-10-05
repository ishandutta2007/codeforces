//By Don4ick
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qwer1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

using namespace std;
const int N = 1e5 + 123, K = 350;
vector< int > g[N], G[N];
int n, q, sz[N];
double p[N], C, d[N];

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%lf", &p[i]);	
		//p[i] = 1.0 * (rand() % 100) / 100;
	}
	
	for(int i = 1; i < n; i++){
		int v, u;
		//v = i, u = rand() % i;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
		sz[v]++;
		sz[u]++;
	}
	
	
	scanf("%d", &q);
	
	double a = 0, b = 0, c = 0, C = 0;
	for(int i = 0; i < q; i++){
		
		if(i == 0){
			b = 0;
			for(int v = 0; v < n; v++)
				b += p[v] * g[v].size();
			a = 0;
			for(int v = 0; v < n; v++)
				a += p[v];
			C = 0;
			for(int v = 0; v < n; v++){
				d[v] = 0;
				for(auto to : g[v]){
					d[v] += p[to];
					if(sz[to] > K)
						G[to].pb(v);
				}
				C += d[v] * p[v];
			}
		
		}
		
		
		
		int v;
		double y;
		//v = rand() % n;
		//y = 1.0 * (rand() % 100) / 100;
		scanf("%d%lf", &v, &y);
		
		a -= p[v];
		b -= p[v] * sz[v];
		
		a += y;
		b += y * sz[v];
		
		if(sz[v] <= K){
			//cerr << i << " " << endl;
			//cout << fixed << setprecision(10) << 1 - a + b - C * 0.5 << endl;
			for(auto to : g[v])
				C = C +  2 * (y - p[v]) * p[to] ;
			for(auto to : G[v])
				d[to] = d[to] - p[v] + y;
		}else{
			C = C +  2 * (y - p[v]) * d[v] ;
			for(auto to : G[v])
				d[to] = d[to] - p[v] + y;
		}
		
		p[v] = y;
		c = C;
		/*
		c = 0;
		for(int v = 0; v < n; v++)
			for(auto to : g[v])
				c += p[v] * p[to];
		if(abs(c - C) > 1e-9)
			cout << "GG" << endl;
		cerr << c << " " << C << endl;
		*/
		/*
		a = b = c = 0;
		for(int v = 0; v < n; v++){
			a += p[v];
			b += p[v] * g[v].size();
			for(auto to : g[v])
				c += (p[v] * p[to])* 0.5;
		}
		*/
		printf("%.10f\n", 1 - a + b - c * 0.5); 
		//cout << fixed << setprecision(10) << 1 - a + b - c * 0.5 << endl;
	}
	return 0;
}