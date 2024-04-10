#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void skriv(int b, int i, int j){
	cout << b+1 << " " << i+1 << " " << j+1 << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vector<vector<pii>> ls(2);
	rep(i,0,n) rep(j,0,n) ls[(i+j)%2].emplace_back(i,j);
	rep(_,0,n*n){
		int a;
		cin >> a;
		--a;
		rep(i,0,2) if(!ls[i].empty() && a != i){
			pii p = ls[i].back();
			ls[i].pop_back();
			skriv(i, p.first, p.second);
			goto done;
		}
		rep(i,0,2) if(!ls[i].empty()){
			pii p = ls[i].back();
			ls[i].pop_back();
			skriv(2, p.first, p.second);
			goto done;
		}
		done: ;
	}
}