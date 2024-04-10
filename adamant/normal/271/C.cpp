#include <cstdlib>
#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

const int INF = 2000000000;

//   

vector<int> p_bf;

vector<int> bfs(vector< vector<int> > g, int s)
{
int n=g.size();
queue<int> q;
q.push (s);
vector<bool> used (n);
vector<int> d (n), p (n);
used[s] = true;
p[s] = -1;
while (!q.empty()) {
	int v = q.front();
	q.pop();
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to]) {
			used[to] = true;
			q.push (to);
			d[to] = d[v] + 1;
			p[to] = v;
		}
	}
}
p_bf=p;
return d;
}

//   (N^2+M)
 
vector<int> p_d;
 
vector<int> dijkstra(vector < vector < pair<int,int> > > g, int s) 
{
    int n=g.size();
	vector<int> d (n, INF),  pn (n);
	d[s] = 0;
	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == INF)
			break;
		u[v] = true;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				pn[to] = v;
			}
		}
	}
	p_d=pn;
	return d;
}

//   (M log N)

vector<int> p_ds;

vector<int> dijkstra_sparse(vector < vector < pair<int,int> > > g, int s) 
{
    int n=g.size();
	vector<int> d (n, INF),  ps (n);
	d[s] = 0;
	priority_queue < pair<int,int> > q;
	q.push (make_pair (0, s));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				ps[to] = v;
				q.push (make_pair (-d[to], to));
			}
		}
	}
	p_ds=ps;
	return d;
}

//  ,   O(n)
int*pr/*=new int[6000000]*/;
int pr_s=0;
//    O(n)
int*erat_pl(int N)
{
int*lp=new int[N+1];
for(int i=0;i<N+1;i++)
lp[i]=0;
 
for (int i=2; i<=N; ++i) {
	if (lp[i] == 0) {
		lp[i] = i;
		pr[pr_s++]=i;
	}
	for (int j=0; j<(int)pr_s && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
		lp[i * pr[j]] = pr[j];
}
return lp;
}

//    O(n log log n)
int*erat(int n)
{
int*prime=new int[n+1];

for(int i=0;i<n+1;i++)
prime[i]=true;

prime[0] = prime[1] = false;
prime[2] = true;
for (int j=4; j<=n; j+=2)
				prime[j] = false;
for (int i=3; i*i<=n; i+=2)
	if (prime[i])
		if (i * 1ll * i <= n)
			for (int j=i*i; j<=n; j+=i)
				prime[j] = false;

return prime;
}

//    
int binpow (int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

//       m
int powmod (int a, int b, int m) {
	int res = 1;
	while (b > 0)
		if (b & 1) {
			res = (res * a) % m;
			--b;
		}
		else {
			a = (a * a) % m;
			b >>= 1;
		}
	return res % m;
}

//  x, ,  n!   k^x   k
int fact_pow (int n, int k) {
	int res = 0;
	while (n) {
		n /= k;
		res += n;
	}
	return res;
}

//    P
int factmod (int n, int p) {
	int res = 1;
	while (n > 1) {
		res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
		for (int i=2; i<=n%p; ++i)
			res = (res * i) % p;
		n /= p;
	}
	return res % p;
}

// 
int gcd (int a, int b) 
{
	while (b) 
    {
		a %= b;
		swap (a, b);
	}
	return a;
}

// 
int lcm (int a, int b) 
{
	return a / gcd (a, b) * b;
}


int main()
{   
    int n,k;
    cin>>n>>k;
    if(n/k<3)
    {
    cout<<-1<<endl;
    return 0;
    }
    int*b=new int[n];
    for(int i=0;i<n;i++)
    b[i]=-1;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    a[i]=i;
    int from=0;
    for(int i=0;i<k-1;i++)
    {
    bool f=false;
    int its[5];
    int cur=0;
    for(int j=from;j<n;j++)
    {
            if(a[j]!=-1)
            {
            its[cur++]=j;
            if(!f)
            {
                  f=true;
                  from=j+1;
            }
            }
            if(cur==5)
            break;
    }
    b[a[its[0]]]=i+1;
    b[a[its[1]]]=i+1;
    b[a[its[4]]]=i+1;
    a[its[0]]=a[its[1]]=a[its[4]]=-1;
    }
    for(int i=0;i<n;i++)
    if(b[i]==-1)
    b[i]=k;
    for(int i=0;i<n;i++)
    cout<<b[i]<<' ';
    cout<<endl;

    return 0;
}