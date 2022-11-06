#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vi> gr(n);

	rep(_,1,n){
		int a,b;
		cin >> a >> b;
		--b, --a;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	int cnt = 0;

	rep(i,0,n) cnt += sz(gr[i])>=3;

	if(cnt >= 2){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;

	if(cnt == 0){
		vi uv;
		rep(i,0,n) if(sz(gr[i])==1) uv.push_back(i);

		cout << 1 << endl;
		cout << uv[0]+1 << ' ' << uv[1]+1 << endl;
	} else {
		int c;
		rep(i,0,n) if(sz(gr[i])>=3) c = i;
		vi vs;
		rep(i,0,n) if(sz(gr[i])==1) vs.push_back(i);
		cout << sz(vs) << endl;
		trav(v, vs) cout << c+1 << ' ' << v+1 << endl;
	}
}