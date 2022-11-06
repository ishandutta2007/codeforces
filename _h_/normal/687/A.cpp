#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <complex>
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

void fail(){
	puts("-1");
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<vi> gr(n+1);
	vector<bool> col(n+1), vis(n+1);
	vi cnt(2);
	rep(_,0,m){
		int u, v;
		cin >> u >> v;
		gr[u].pb(v);
		gr[v].pb(u);
	}
	rep(i,1,n+1){
		if(!vis[i]){
			stack<int> st;
			vis[i] = 1;
			st.push(i);
			while(!st.empty()){
				int v = st.top();
				++cnt[col[v]];
				st.pop();
				for(int u : gr[v]){
					if(vis[u] && col[u] == col[v])
						fail();
					else if(!vis[u]){
						col[u] = !col[v];
						vis[u] = 1;
						st.push(u);
					}
				}
			}
		}
	}
	rep(t,0,2){
		cout << cnt[t] << endl;
		rep(i,1,n+1) if(col[i] == t) cout << i << ' ';
		cout << endl;
	}
}