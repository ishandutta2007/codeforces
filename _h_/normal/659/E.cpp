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
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;

int main(){
	cin.sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	vector<set<int> > gr(n);
	rep(_,0,m){
		int x,y;
		cin >> x >> y;
		gr[--x].insert(--y);
		gr[y].insert(x);
	}
	int ans = 0;
	stack<int> st;
	rep(i,0,n) if(gr[i].size() < 2) st.push(i);
	while(!st.empty()){
		int v = st.top();
		st.pop();
		if(gr[v].empty()){
			++ans;
			continue;
		}
		int u = *gr[v].begin();
		gr[u].erase(v);
		if(gr[u].size() == 1) st.push(u); 
	}
	cout << ans << endl;
}