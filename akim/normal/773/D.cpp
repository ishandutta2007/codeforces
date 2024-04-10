#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = 2010, mod = int(1e9)  + 7; 
const ll inf = (ll)(1e18);

int n;
ll mn = mod;
ll a[N][N], x[N], b[N][N];
ll d[N];

bool u[N];

priority_queue <pair<ll, int> > q;

int main () {
	scanf("%d",&n);
	for(int i = 1;  i <= n; i++){
		x[i] = mod;
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			scanf("%lld",&a[i][j]);
			x[i] = min(x[i], a[i][j]);
			mn = min(mn, a[i][j]);
			a[j][i] = a[i][j];
			x[j] = min(x[j], a[j][i]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == mn){
				u[i] = 1;
				u[j] = 1;
			}
			if(i != j) a[i][j] -= mn;
		}
		d[i] = inf;
	}
	for(int i = 1; i <= n; i++){
		x[i] -= mn;
		for(int j = 1; j <= n; j++){
			if(i != j){
				b[i][j] = min(a[i][j], 2 * x[i]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(u[i]){
			d[i] = 0;
			q.push(mp(0,i));
		}
	}
	while(!q.empty()){
		int v = q.top().s;
		ll dis = -q.top().f;
		q.pop();
		if(dis > d[v]) continue;
		for(int i = 1; i <= n; i++){
			if(v != i && d[i] > d[v] + b[i][v]){
				d[i] = d[v] + b[i][v];
				q.push(mp(-d[i], i));
			}
		}
	}
	for(int i = 1; i <= n; i++){
	    printf("%lld\n", 1ll * (n - 1) * mn + d[i]);
	}
return 0;
}