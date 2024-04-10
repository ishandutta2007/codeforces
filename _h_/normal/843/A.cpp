#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vi as(n);
	trav(x , as) cin >> x;
	map<int,int> ren;
	trav(x, as) ren[x] = 0;
	int ix = 0;
	trav(pa, ren) pa.second = ix++;
	vector<vi> ans;
	vector<bool> vis(n, 0);
	rep(i,0,n) if(!vis[i]){
		int j = i;
		vi ny;
		do {
			vis[j] = 1;
			ny.push_back(j);
			j = ren[as[j]];
		} while(j != i);
		ans.push_back(ny);
	}
	cout << sz(ans) << endl;
	trav(v, ans){
		cout << sz(v);
		trav(x, v) cout << ' ' << x+1;
		cout << endl;
	}
}