#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n;
string v[55];
int a[55][55], z[55], d[55], g[55], p[55];
map<string, int> id;

bool cmp(int i, int j) {
	if (z[i] != z[j]) return z[i] > z[j];
	if (d[i] != d[j]) return d[i] > d[j];
	return g[i] > g[j];
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> n;
	REP (i, n) {
		cin >> v[i];
		id[v[i]] = i;
		p[i] = i;
	}
	REP (k, n * (n - 1) / 2) {
		string s;
		cin >> s;
		int x, y;
		scanf("%d : %d", &x, &y);
		REP (u, sz(s))
			if (s[u] == '-') {
				int i = id[s.substr(0, u)], j = id[s.substr(u + 1)];
				if (x > y) z[i] += 3;
				if (y > x) z[j] += 3;
				if (x == y) ++z[i], ++z[j];
				d[i] += x - y;
				d[j] += y - x;
				g[i] += x;
				g[j] += y;
			}
	}
	REP (j, n) REP (i, j) 
		if (cmp(p[j], p[i])) 
			swap(p[i], p[j]);
	vector <string> r(n / 2);
	REP (i, sz(r)) r[i] = v[p[i]];
	sort(all(r));
	REP (i, sz(r)) cout << r[i] << endl;
	return 0;
}