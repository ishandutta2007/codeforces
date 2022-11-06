#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

vector<pii> ans;

void fun(int fr, int to, int e){
	if(e == 0) return;
	int mi = (fr + to) / 2;
	fun(fr, mi, e-1);
	fun(mi, to, e-1);
	rep(i,fr,mi) ans.emplace_back(i, i + mi-fr);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	int e = 0;
	while( (1<<e)*2 < n ) ++e;
	fun(1, 1 + (1<<e), e);
	fun(n+1-(1<<e), n+1, e);

	cout << sz(ans) << endl;
	trav(pa, ans) cout << pa.first << " " << pa.second << endl;
}