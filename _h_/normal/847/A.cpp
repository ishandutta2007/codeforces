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
	vi ls(n), rs(n);
	rep(i,0,n) cin >> ls[i] >> rs[i];
	vi xs, ys;
	rep(i,0,n){
		if(ls[i]==0){
			xs.push_back(i);
			int j = i;
			while(rs[j] != 0) j = rs[j]-1;
			ys.push_back(j); 
		}
	}
	rep(i,1,sz(xs)){
		int x = xs[i], y = ys[(i+1)%(sz(xs))];
		ls[x] = y+1;
		rs[y] = x+1;
	}
	rep(i,0,n) cout << ls[i] << ' ' << rs[i] << endl;
}