#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>]
using namespace std;
ll inf = (ll) (1e18);
int n, m, k, c[600], a[111100], l, x, v, u;
int parent[111000], rank[111000];
ll d[600][600];
ll minx(ll uu, ll aa){
	if(uu < aa) return uu;
	return aa;
}
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
void make_set (int v) {
	parent[v] = v;
	rank[v] = 0;
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rank[a] < rank[b])
			swap (a, b);
		parent[b] = a;
		if (rank[a] == rank[b])
			++rank[a];
	}
}
int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif                 
    for(int i = 0; i < 550; i++){
    	for(int j = 0; j < 550; j++)
    		d[i][j] = inf;
    }
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
    	cin >> c[i];
    	for(int j = 1; j <=  c[i]; j++){
    		a[j+l] = i+1;
    		make_set(j+l);
    	}
    	l += c[i];
    }
    for(int i = 0; i < m; i++){
    	cin >> v >> u >> x;
    	if(x == 0){
    		union_sets(v, u);		
    	}
    	d[a[v]][a[u]] = minx(d[a[v]][a[u]], x);
    	d[a[u]][a[v]] = d[a[v]][a[u]];
    }
    for(int i = 1; i <= k; i++){
    	for(int j = 1; j <= k; j++){
    		for(int z = 1; z <= k; z++){
    			d[j][z] = minx(d[j][z], d[j][i] + d[i][z]);
    		}
    	}
    }
    l = 0;
    for(int i = 0; i < k; i++){
    	int uu = l+1;
    	for(int j = 2; j <= c[i]; j++){
    		if(find_set(uu) != find_set(j+l)){
    			cout << "No";
    			return 0;
    		}
    	}
    	l+=c[i];
    }
    cout << "Yes" << endl;
    for(int i =1; i<=k; i++){
    	for(int j= 1; j <= k; j++){
    		if(d[i][j] == inf && i!=j) cout << -1 << " ";
    		else if(i == j) cout << "0 ";
    		else cout << d[i][j] << " ";
    	}
    	cout << endl;
    }
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}